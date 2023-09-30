import java.io.*;
import java.util.*;

public class passing_travis {
	public static void main(String[] Args) throws Exception {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));

		// Read in the number of test cases
		int t = sc.nextInt();

		// Loop through each case
		while (t --> 0) {

			// Read in the size of the class
			int n = sc.nextInt();

			// Start a total of all the possible probabilities
			int tot = 0;

			// Create a graph for segmentation
			Flow graph = new Flow(n);

			// Get the probabilities from being in the first class
			for (int k = 0; k < n; k++) {
				int curEdge = parse(sc.next());
				tot += curEdge;
				graph.add(graph.s, k, curEdge, true);
			}

			// Get the probabilities from being in the second class
			for (int k = 0; k < n; k++) {
				int curEdge = parse(sc.next());
				tot += curEdge;
				graph.add(k, graph.t, curEdge, true);
			}

			// Get the probabilities from forming study groups
			for (int k = 0; k < n; k++) {
				for (int j = 0; j < n; j++) {
					int curEdge = parse(sc.next());
					tot += curEdge;
					graph.add(k, j, curEdge, false);
				}
			}

			// Compute the answer as the total probability minus the minimum cut
			// of the graph
			int ans = tot - graph.getFlow();
			
			// Print the answer
			out.printf("%d.%02d%n", ans / 100, ans % 100);
		}
		
		// close the output
		out.close();
	}

	// Parsing function
	private static int parse(String next) {
		next = next.trim().replaceAll("\\.", "");
		if(next.charAt(0) == '.'){
			next = "0" + next;
		}
			
		while (next.length() > 1 && next.charAt(0) == '0') {
			next = next.substring(1);
		}
		return Integer.parseInt(next);
	}

	// Max Flow class
	public static class Flow {
		ArrayDeque<Edge> stk = new ArrayDeque<Edge>();
		int N, fptr, bptr, s, t, oo = 987654321;
		ArrayList<Edge>[] adjj;
		Edge[][] adj;
		int[] q, dist, pool;

		Flow(int NN) {
			N = (t = (s = NN) + 1) + 1;
			adjj = new ArrayList[N];
			for (int i = 0; i < N; i++)
				adjj[i] = new ArrayList<Edge>();
			adj = new Edge[N][0];
			dist = new int[N];
			pool = new int[N];
			q = new int[N];
		}

		void add(int i, int j, int cap, boolean directed) {
			Edge fwd = new Edge(i, j, cap, 0);
			Edge rev = new Edge(j, i, 0, directed ? 0 : -cap);
			adjj[i].add(rev.rev = fwd);
			adjj[j].add(fwd.rev = rev);
		}

		int augment() {
			Arrays.fill(dist, Integer.MAX_VALUE);
			pool[t] = dist[s] = fptr = bptr = 0;
			pool[q[bptr++] = s] = oo;
			while (bptr > fptr && q[fptr] != t)
				for (Edge e : adj[q[fptr++]]) {
					if (dist[e.i] < dist[e.j])
						pool[e.j] += e.carry = Math.min(e.cap - e.flow,
								pool[e.i]);
					if (dist[e.i] + 1 < dist[e.j] && e.cap > e.flow)
						dist[q[bptr++] = e.j] = dist[e.i] + 1;
				}
			if (pool[t] == 0)
				return 0;
			Arrays.fill(pool, fptr = bptr = 0);
			pool[q[bptr++] = t] = oo;
			while (bptr > fptr)
				for (Edge e : adj[q[fptr++]]) {
					if (pool[e.i] == 0)
						break;
					int f = e.rev.carry = Math.min(pool[e.i], e.rev.carry);
					if (dist[e.i] > dist[e.j] && f != 0) {
						if (pool[e.j] == 0)
							q[bptr++] = e.j;
						pool[e.i] -= f;
						pool[e.j] += f;
						stk.push(e.rev);
					}
				}
			int res = pool[s];
			Arrays.fill(pool, 0);
			pool[s] = res;
			while (stk.size() > 0) {
				Edge e = stk.pop();
				int f = Math.min(e.carry, pool[e.i]);
				pool[e.i] -= f;
				pool[e.j] += f;
				e.flow += f;
				e.rev.flow -= f;
			}
			return res;
		}

		int getFlow() {
			int res = 0, f = 1;
			for (int i = 0; i < N; i++)
				adj[i] = adjj[i].toArray(adj[i]);
			while (f != 0) {
				res += f = augment();
			}
			return res;
		}
	}

	// Edge class
	public static class Edge {
		int i, j, cap, flow, carry;
		Edge rev;

		Edge(int ii, int jj, int cc, int ff) {
			i = ii;
			j = jj;
			cap = cc;
			flow = ff;
		}
	}
}