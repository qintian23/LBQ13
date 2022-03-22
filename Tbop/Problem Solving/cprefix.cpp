#include <stdio.h>
#include <assert.h>

// 烙饼排序实现
class CPrefixSorting
{
    public:

        CPrefixSorting();
        ~CPrefixSorting();
        void Run(int* pCakeArray, int nCakeCnt);
        void Output();

    private:

        void Init(int* pCakeArray, int nCakeCnt);
        int UpperBound(int nCakeCnt);
        int LowerBound(int* pCakeArray, int nCakeCnt);
        void Search(int step);
        bool IsSorted(int* pCakeArray, int nCakeCnt);
        void Reverse(int nBegin, int nEnd);

    private:

        int* m_CakeArray;
        int m_nCakeCnt;
        int m_nMaxSwap;

        int* m_SwapArray;

        int* m_ReverseCakeArray;
        int* m_ReverseCmakeArraySwap;
        int m_nSearch;
};

CPrefixSorting::CPrefixSorting()
{
    m_nCakeCnt=0;
    m_nMaxSwap=0;
}

CPrefixSorting::~CPrefixSorting()
{
    if(m_CakeArray!=NULL)
        delete m_CakeArray;
    if(m_SwapArray!=NULL)
        delete m_SwapArray;
    if(m_ReverseCakeArray!=NULL)
        delete m_ReverseCakeArray;
    if(m_ReverseCmakeArraySwap!=NULL)
        delete m_ReverseCmakeArraySwap;
}

void CPrefixSorting::Run(int* pCakeArray, int nCakeCnt)
{
    Init(pCakeArray,nCakeCnt);

    m_nSearch=0;
    Search(0);
}

void CPrefixSorting::Output()
{
    for (int i = 0; i < m_nMaxSwap; i++)
    {
        printf("%d ",m_SwapArray[i]);
    }
    
    printf("\n |Search Times| : %d\n", m_nSearch);
    printf("Total Swap Times = %d\n", m_nMaxSwap);
}

void CPrefixSorting::Init(int* pCakeArray, int nCakeCnt)
{
    assert(pCakeArray!=NULL);
    assert(nCakeCnt>0);

    m_nCakeCnt=nCakeCnt;

    // 初始化烙饼数组
    m_CakeArray=new int[m_nCakeCnt];
    assert(m_CakeArray!=NULL);
    for (int i = 0; i < m_nCakeCnt; i++)
        m_CakeArray[i]=pCakeArray[i];

    // 设置最多交换次数信息
    m_nMaxSwap=UpperBound(m_nCakeCnt);

    // 初始化中间交换结果数组
    m_SwapArray=new int[m_nMaxSwap+1];
    assert(m_SwapArray!=NULL);

    // 初始化中间交换结果信息
    m_ReverseCakeArray=new int[m_nCakeCnt];
    for (int i = 0; i < m_nCakeCnt; i++)
        m_ReverseCakeArray[i]=m_CakeArray[i];
    m_ReverseCmakeArraySwap=new int[m_nMaxSwap];
}

int CPrefixSorting::UpperBound(int nCakeCnt)
{
    return nCakeCnt*2;
}

int CPrefixSorting::LowerBound(int* pCakeArray, int nCakeCnt)
{
    int t, ret=0;

    // 根据当前数组的排序信息情况来判断最少需要交换次数
    for (int i = 0; i < nCakeCnt; i++)
    {
        // 判断位置相邻的两个烙饼，是否为尺寸排序上相邻
        t=pCakeArray[i]-pCakeArray[i-1];
        if((t==1) || (t==-1)){}
        else ret++;
    }
    return ret;
}

void CPrefixSorting::Search(int step)
{
    int i, nEstimate;

    m_nSearch++;

    // 估算这次搜索所需要的最少交换次数
    nEstimate=LowerBound(m_ReverseCakeArray,m_nCakeCnt);
    if(step+nEstimate>m_nMaxSwap)
        return;
    
    // 如果已经排好序，即翻转完成，输出结果
    if(IsSorted(m_ReverseCakeArray,m_nCakeCnt))
    {
        if(step<m_nMaxSwap)
        {
            m_nMaxSwap=step;
            for (i = 0; i < m_nMaxSwap; i++)
                m_SwapArray[i]=m_ReverseCmakeArraySwap[i];
        }
        return ;
    }

    // 递归进行翻转
    for ( i = 1; i < m_nCakeCnt; i++)
    {
        Reverse(0,i);
        m_ReverseCmakeArraySwap[step]=i;
        Search(step+1);
        Reverse(0,i);
    }
}

bool CPrefixSorting::IsSorted(int* pCakeArray, int nCakeCnt)
{
    for (int i = 1; i < nCakeCnt; i++)
    {
        if(pCakeArray[i-1]>pCakeArray[i])
            return false;
    }
    return true;
}

void CPrefixSorting::Reverse(int nBegin, int nEnd)
{
    assert(nEnd>nBegin);
    int i,j,t;

    // 翻转烙饼信息
    for (int i = nBegin, j = nEnd; i<j; i++,j--)
    {
        t=m_ReverseCakeArray[i];
        m_ReverseCakeArray[i]=m_ReverseCakeArray[j];
        m_ReverseCakeArray[j]=t;
    }
}