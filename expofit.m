function sols = expofit(x,y)
%Umanga Bista
%fitting scientific observations exponentially
%   y=a*exp(b*x)
Y=log(y);
[r c]=size(Y);
mat=zeros(2,3);
for i=1:2
    for j=1:2
        for k=1:c
            mat(i,j)=mat(i,j)+x(k)^(i+j-2);
        end
    end
end
for i=1:2
    for k=1:c
        mat(i,3)=mat(i,3)+Y(k)*x(k)^(i-1);
    end
end
sol=gauss_jordan(mat);
sol(1)=exp(sol(1));

end

