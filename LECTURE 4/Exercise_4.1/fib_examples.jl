using BenchmarkTools, Memoization, Random

# serial version
function fib(n::T) where {T<:Integer}
   if n < 2
      return n
   else
      return fib(n - 1) + fib(n - 2)
   end
end

# tasking version
function fib_tasks(n::T) where {T<:Integer}
   if n < 2
      return n
   else
      a = Threads.@spawn fib(n - 1)
      b = Threads.@spawn fib(n - 2)
      return fetch(a) + fetch(b)
   end
end

# tight loop with no allocations
function fib_loop(n::T) where {T<:Integer}
   a = 0
   b = 1
   c = 0
   for m in 1:n
      c = a
      a = a + b
      b = c
   end
   return a
end

# memoized tail-recursion
@memoize function fib_memo(n::T) where {T<:Integer}
   if n < 2
      return n
   else
      return fib_memo(n - 1) + fib_memo(n - 2)
   end
end

# fast doubling recursion
function fib_doubler(n::T) where {T<:Integer}
	if n < 2
		return n
	else
		a = fib_doubler(n ÷ 2)
		b = a + fib_doubler((n ÷ 2) - 1)
		c = a * (2b - a)
		d = a * a + b * b
		if iseven(n)
			return c
		else
			return d
		end
	end
end

function fib_closed(n::T) where {T <: Integer}
	ϕ = ( 1.0 + sqrt( 5.0 ) ) *  0.5
	return T(round(ϕ^n / sqrt( 5.0 )))
end

function test()
	for n in rand(1:50, 20)
		Fn = fib(n);
		@assert Fn == fib_tasks(n);
		@assert Fn == fib_loop(n);
		@assert Fn == fib_memo(n);
		@assert Fn == fib_doubler(n);
		@assert Fn == fib_closed(n);
	end
	return nothing
end

function main()
   t = Array{Float64,2}(undef, 5, 913);
   t .= Inf;
   ns = 1:size(t,2)
   ns = shuffle(ns)	# Note: fairly timing the memoized version should use a shuffle (random index permutation)
   for n in ns
      @show n
      if n <= 50
	      t[1, n] = @belapsed fib($n)
	      t[2, n] = @belapsed fib_tasks($n)
      end
      t[3, n] = @belapsed fib_loop($n)
      t[4, n] = @belapsed fib_doubler($n)
      t[5, n] = @belapsed fib_memo($n)
   end
   return t
end

main()
