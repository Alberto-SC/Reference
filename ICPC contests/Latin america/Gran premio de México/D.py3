if __name__ == '__main__':
	T = int(input())
	for i in range(0, T):
		try:
			N = int(input())
			nw = 1
			cont = 1
			while (True):
				if ((nw // N) * N == nw):
					print(cont)
					break
				cont += 1
				nw = (nw * 10) + 1
		except EOFError:
			break