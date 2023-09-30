for i in range(10,21):
  mx = 5*(i**2)
  sum = 0
  for j in range(1,i):
    sum+=(i-j)*(i**2)

  print(sum,mx)