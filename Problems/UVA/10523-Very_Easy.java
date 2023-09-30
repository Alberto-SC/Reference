import java.math.BigInteger;
import java.util.Scanner;
class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNextInt()){
			int n = scanner.nextInt();
			BigInteger a = scanner.nextBigInteger();
			BigInteger sol = BigInteger.ZERO;
			BigInteger p = BigInteger.ONE;
			for(int i = 1;i<=n;i++){
				p = p.multiply(a);
				sol = sol.add(p.multiply(BigInteger.valueOf(i)));
			}
			System.out.println(sol);
		}
	}
}








































