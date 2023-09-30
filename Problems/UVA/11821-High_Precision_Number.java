import java.util.*;
import java.math.*;

class Main{
	static final BigDecimal ZERO = new BigDecimal("0");
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		while(T-- >0 ){
			BigDecimal res = ZERO;
			while(true)	{
				BigDecimal n = scanner.nextBigDecimal();
				if(n.equals(ZERO)){
					char[] f = res.toString().toCharArray();
					int size = f.length -1;
					while(size>= 0 && f[size] == '0')--size;
					if( size >= 0 && f[size] == '.' )	--size;
					for (int i = 0; i <= size; i++)
						System.out.print(f[i]);
					System.out.println();
					break;
				}	
				res= res.add(n);
			}
		}


	}
}
