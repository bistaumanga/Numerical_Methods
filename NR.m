function [x f] = NR(fx,x)
x=linspace(x-1,x,1);
df=deriv(fx,x,1e-3,'forward3');

if df==0
    error('derivative zero at initial guess');
end
f=Inf;
while(f>10e-10 | df>10e-5)
    f=feval(fx,x);
    df=deriv(fx,x,1e-3,'forward3');
    x=x-f/df;
end