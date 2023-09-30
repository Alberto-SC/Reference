// Arup Guha (modified by Ali Orooji for 2021)
// 8/23/2015
// Solution to 2021 UCF Practice Local Contest
// Problem: Balanced Strings (balance)

import java.util.*;

public class balance {

	final public static String VOWELS = "aeiouy";

	// Limits for our exponents.
	final public static int MAX_EXP_6 = 24;
	final public static int MAX_EXP_20 = 14;
	public static long[] POW6;
	public static long[] POW20;

	public static void main(String[] args) {

		// Handy precomputation for this problem.
		POW6 = new long[MAX_EXP_6+1];
		fillPow(POW6, 6);
		POW20 = new long[MAX_EXP_20+1];
		fillPow(POW20, 20);

		Scanner stdin = new Scanner(System.in);
		
		System.out.println( solve(stdin.next()) );
		
	}// end of main()
	

	// Fills arr so arr[i] = base to the power i.
	public static void fillPow(long[] arr, int base)	{
		arr[0] = 1;
		for (int i=1; i<arr.length; i++)
			arr[i] = arr[i-1]*base;
	}
	

	public static long solve(String s) {

		int vLoc = -1, cLoc = -1, vCount = 0, cCount = 0, n = s.length();

		// Find indexes of consonants and vowels.
		for (int i=0; i<s.length(); i++) {
			if (s.charAt(i) == '?') continue;

			// Process a vowel.
			if (VOWELS.contains(s.charAt(i)+"")) {
				vCount++;
				if (vLoc == -1) vLoc = i%2;
				else if (vLoc%2 != i%2) return 0;
			}

			// Process a consonant.
			else {
				cCount++;
				if (cLoc == -1) cLoc = i%2;
				else if (cLoc%2 != i%2) return 0;
			}
		}

		// Tricky case where consonants and vowels are "lined up" in same slots.
		if (cLoc != -1 && vLoc != -1 && cLoc == vLoc) return 0;

		// Case where starting letter can be either vowel or consonant.
		if (cLoc == -1 && vLoc == -1)
			return POW6[n/2]*POW20[(n+1)/2] + POW6[(n+1)/2]*POW20[n/2];

		// Consonant must come first
		if (cLoc == 0 || vLoc == 1)
			return POW20[(n+1)/2-cCount]*POW6[n/2-vCount];

		// If we get here, a vowel must come first.
		return POW6[(n+1)/2-vCount]*POW20[n/2-cCount];
		
	}// end of solve()
	
}// end of class