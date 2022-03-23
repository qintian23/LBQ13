function V = MP_Vand(x,M,P)
    Nx = size(x,2);
    V = zeros(M*(ceil(P/2)),Nx);
    for i=M:Nx
      for m=1:M
        for p=1:ceil(P/2)
          V(m+(p-1)*M,i) = x(i-m+1)*abs(x(i-m+1))^((p-1)*2);
        end
      end
    end
  end