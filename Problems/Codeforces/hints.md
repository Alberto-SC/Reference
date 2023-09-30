# Complexity

- If problem is check for all multiples of a number in [1,n] and this multiples don´t exed maxn complexity is (maxn log(maxn))
- Sum of n/1+ n/2 + n/3 + n/4 + ... is nlogn
- Merge many sets can be do it in n logn if we insert elements of the minor set to the mayor set
- Strings? Do you made a suffix array or suffix tree
- Graphs? shortes Path with two variables or many types of edges? try to clone graph
- try to decompose the formula
- TLE? and modulos , try to do less % operations if you have long long do modulo only when a>=(mod*8) where modulo is something like 1e9+7
- Best of all posibilities whit small n like 30-40 try meet in the middle
- need a subset whit some features and at least n/2 elements? try randomize
- Boolean assigments?  2-sat? basisxor? SLAE?
- Queries about paths with some specific value like sum xor? try to decompose with centroid decomposition and solve for each tree root in each centroid 

# tricks
- ((x % a) % a*b) =  ((x % a*b) % a) = x%a
- $a+b = a^b + 2 \times a\&b$
- a+b= (a | b)+(a & b).
- a1=(a01+a12−a02)/2
- lcm(a, gcd(b, c)) = gcd(lcm(a, b), lcm(a, c)) -- (1)
- gcd(a, lcm(b, c)) = lcm(gcd(a, b), gcd(a, c)) -- (2)
- gcd(a,b) = gcd(a,b-a);
- Desplazar coeficientes de multiplicación pasar de esto w *3 + x*2 + y*1 -> w*4 + x*3 +y*2 +z*1 usar doble acumulado,
  La diferencia ente uno y otros es w+x+y+z
- El numero de maneras de conectar un grafo con k componentes conexas con el minimo número de aristas
  donde s_i es el tamaño del componente( s1 * s2 ... sk ) ×  n^(k -2)
- Sum of nrc(i*2,n) 0<= i <= n/2 is 2^(n-1)
- Sum of nrc(i,n) 0<= i <= n is 2^(n)
- φ(ip) = pφ(i).
-A number in base 10 has non-repeating decimals if its reduced fraction s/t has a denominator in the form t = ${2^{v}}·{5^{w}}

# TO do 
- Check list of themes 
- Check parity
- querys on path of tree? if it´s only to root is enough to do an euler traversal and flat the tree in other case use HLD
