//This solution should not pass

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class stars_fixed {
	public static int[] dx = { 1, -1, 0, 0 };
	public static int[] dy = { 0, 0, 1, -1 };

	public static boolean[][] mustStamp;
	public static boolean[][] hasMark;
	public static boolean[][] canStamp;
	public static int[][] numCanMark;
	public static PrintWriter out;

	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(System.in);
		 Scanner sc = new Scanner(new File("stars.in"));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int cc = 0;
		int n = sc.nextInt();
		for (int curCase = 0; curCase < n; curCase++) {
			h = sc.nextInt();
			w = sc.nextInt();
			hasMark = new boolean[h][w];

			for (int k = 0; k < h; k++) {
				String s = sc.next().trim();
				for (int j = 0; j < w; j++) {
					if (s.charAt(j) == '#') {
						hasMark[k][j] = true;
					}
				}
			}

			canStamp = new boolean[h][w];
			boolean[][] canMark = new boolean[h][w];
			numCanMark = new int[h][w];

			int canMarkCount = 0;

			for (int y = 1; y < h - 1; y++) {
				for (int x = 1; x < w - 1; x++) {
					canStamp[y][x] = hasMark[y][x];
					for (int i = 0; i < 4 && canStamp[y][x]; i++) {
						int ty = y + dy[i];
						int tx = x + dx[i];
						canStamp[y][x] = hasMark[ty][tx];
					}

					if (canStamp[y][x]) {
						canMark[y][x] = true;
						canMarkCount++;
						numCanMark[y][x]++;
						for (int i = 0; i < 4 && canStamp[y][x]; i++) {
							int ty = y + dy[i];
							int tx = x + dx[i];
							canMark[ty][tx] = true;
							numCanMark[ty][tx]++;
						}
					}
				}
			}

			mustStamp = new boolean[h][w];
			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x++) {
					if (numCanMark[y][x] == 1) {
						if (canStamp[y][x]) {
							mustStamp[y][x] = true;
						}
						for (int i = 0; i < 4; i++) {
							int ty = y + dy[i];
							int tx = x + dx[i];
							if (tx >= 0 && ty >= 0 && tx < w && ty < h
									&& canStamp[ty][tx]) {
								mustStamp[ty][tx] = true;
							}
						}
					}
				}
			}
			canMarkCount = 0;
			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x++) {
					if (canStamp[y][x] && !mustStamp[y][x]) {
						canMarkCount++;
					}
				}
			}

			boolean good = true;

			for (int y = 0; y < h && good; y++) {
				for (int x = 0; x < w && good; x++) {
					good = (hasMark[y][x] == canMark[y][x]);
				}
			}

			// Base case check
			if (w <= 4 || h <= 4) {
				ans = 0;
				for (int y = 0; y < h; y++) {
					for (int x = 0; x < w; x++) {
						if (mustStamp[y][x]) {
							ans++;
						}
					}
				}
				if (!good) {
					out.printf("Image #%d: impossible%n%n", ++cc);
				} else {
					out.printf("Image #%d: %d%n%n", ++cc, ans);
				}
			} else {
				ans = h * w;
				memo = new int[h][(1 << ((w - 4) * 2))];
				for (int y = 0; y < h; y++) {
					Arrays.fill(memo[y], -1);
				}
				if (!good) {
					out.printf("Image #%d: impossible%n%n", ++cc);
				} else {
					ans = rec(0, 0);
					out.printf("Image #%d: %d%n%n", ++cc, ans);
				}
			}
		}
		out.close();
	}

	public static int h, w;
	public static int ans;
	public static int[][] memo;

	public static int rec(int y, int map) {
		if (y == h) {
			return 0;
		}
		if (memo[y][map] != -1) {
			return memo[y][map];
		}
		int nMap = (map & ((1 << (w - 4)) - 1)) << (w - 4);
		int best = 1000;
		if (y > 0) {
			for (int i = 0; i < (1 << (w - 4)); i++) {
				boolean good = true;
				for (int x = 0; x < w - 4; x++) {
					if (mustStamp[y][x + 2] && (i & (1 << x)) == 0) {
						good = false;
					}
					if (!canStamp[y][x + 2] && (i & (1 << x)) != 0) {
						good = false;
					}
				}
				for (int x = 0; x < w - 4; x++) {
					if (hasMark[y - 1][x + 2] && !mustStamp[y-1][x+2] && (map & (1<<x)) == 0) {
						boolean cov = ((i & (1 << x)) != 0);
						for (int ii = 0; ii < 4; ii++) {
							int tx = x + 2 + dx[ii];
							int ty = y - 1 + dy[ii];
							if (tx >= 0 && tx < w && ty >= 0 && ty < h
									&& mustStamp[ty][tx]) {
								cov = true;
							}
							if (tx >= 2
									&& tx < w - 2
									&& ty < y
									&& ty >= 0
									&& (map & (1 << (((dy[ii] == -1) ? w - 4
											: 0) + (tx - 2)))) != 0) {
								cov = true;
							}
							
						}
						if (!cov) {
							good = false;
						}
					}
				}
				if (!good) {
					continue;
				}
				best = Math.min(best,
						rec(y + 1, nMap + i) + Integer.bitCount(i)
								+ (mustStamp[y][1] ? 1 : 0)
								+ (mustStamp[y][w - 2] ? 1 : 0));
			}
		} else {
			best = rec(1, map);
		}
		memo[y][map] = best;
		return best;
	}
}

/*



1
9 9
...###...
..#####..
.#######.
#########
#########
#########
.#######.
..#####..
...###...


*