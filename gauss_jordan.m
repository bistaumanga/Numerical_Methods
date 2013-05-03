function [sol A]=gauss_jordan(A)
%Gauss-Jordan Method
%Umanga Bista, IOE, Pulchowk Campus
[rows cols]=size(A);
if rows~=cols-1
    error('Incorrect order of input matrix');
end
for j=1:rows
    if A(j,j)==0
        error('zero at diagonal');
    end
    A(j,:)=A(j,:)/A(j,j);
end
for j=1:cols-1
    for i=1:rows
        if A(j,:)==A(uint8(fix(i+rows)/rows))
            error('two rows identical');
        end
        if i~=j
            A(i,:)=A(i,:)-A(i,j)/A(j,j)*A(j,:);
        end
    end
end

for j=1:rows
    sol(j)=A(j,cols)/A(j,j);
end

            
                