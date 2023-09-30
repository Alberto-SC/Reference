//_________________________String to int_______________________//
int str_int(string st){
    int n;
    stringstream ss(st);
    ss>>n;
    return n;
}

//____________________________pow of large numbers_________________________________//
long long powerStrings(string sa, string sb){
    // Convert strings to number
    long long a = 0, b = 0;
    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (sa[i] - '0')) % MOD;
    for (int i = 0; i < sb.length(); i++)
        b = (b * 10 + (sb[i] - '0')) % (MOD - 1);
    return Mod(a, b);
}
//________________pow of string_________________//
string b = "100000000000000000000000000";
long long remainderB = 0;
long long MOD = 1000000007;
    // using Fermat Little
for (int i = 0; i < b.length(); i++)
	remainderB = (remainderB * 10 + b[i] - '0') % (MOD - 1);
