from functools import lru_cache
with open("in_j1") as lectura:
    data = lectura.read()
jolt = [0]+[int(i) for i in data.split("\n")]
jolt.sort()
@lru_cache(None) 
def dp(indice):
    if indice == len(jolt) - 1:
        return 1
    total = 0
    sig_indice = indice + 1
    while sig_indice < len(jolt) and (jolt[sig_indice] - jolt[indice]) <= 3:
        total += dp(sig_indice)
        sig_indice += 1

    return total
dp_res = dp(0)
print(dp_res)