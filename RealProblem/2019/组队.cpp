#include<iostream>
using namespace std;
typedef long long ll;
int one[20] = {97, 92, 0, 0, 89, 82, 0, 0, 0, 95, 0, 0, 94, 0, 0, 0, 98, 93, 0, 0};
int two[20] = {90, 85, 0, 0, 83, 86, 0, 97, 0, 99, 0, 0, 91, 83, 0, 0, 83, 87, 0, 99};
int three[20] = {0, 96, 0, 0, 97, 0, 0, 96, 89, 0, 96, 0, 0, 87, 98, 0, 99, 92, 0, 96};
int four[20] = {0, 0, 0, 80, 0, 0, 87, 0, 0, 0, 97, 93, 0, 0, 97, 93, 98, 96, 89, 95};
int five[20] = {0, 0, 93, 86, 0, 0, 90, 0, 0, 0, 0, 98, 0, 0, 98, 86, 81, 98, 92, 81};
int main()
{
    int ma = 0;
    for(int i = 0; i < 20; i++){
      for(int j = 0; j < 20; j++){
        for(int k = 0; k < 20; k++){
          for(int l = 0;l < 20; l++){
            for(int m = 0; m < 20; m++){
              if((i != j)&&(i != k)&&(i != l)&&(i != m)
              &&(j != k)&&(j != l)&&(j != m)
              &&(k != l)&&(k != m)
              &&(l != m))
                {
                if((one[i] + two[j] + three[k] + four[l] + five[m]) > ma){
                  ma = one[i] + two[j] + three[k] + four[l] + five[m];
                }
              }
            }
          }
        }
      }
    }
    cout << ma << endl;
    return 0;
}