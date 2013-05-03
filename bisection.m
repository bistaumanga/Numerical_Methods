function [c fc] = bisection(fx,a,b,varargin)
%Bisection Method
%n Bisections to approximate
%Umanga Bista,IOE, Pulchowk Campus
%or use this for default arguments
%if ~exist('pr','var'), pr=1e-10; end
if length(varargin) > 1
    error('only 1 optional input, for precision');
   end
% set default for optional input precision
if length(varargin)==0 
    varargin={1e-10};
    end
%assign inputs to required variable array
[pr] = varargin{:};
fa=feval(fx,a);
fb=feval(fx,b);
if fa*fb>0
    error('please enter guesses that encloses the root');
end
fc=Inf;
    while abs(fc) > pr
        c=(a+b)/2;
        fc=feval(fx,c);
        if fc*fa<0 
            b=c;
        else a=c;
        end
    end
end

