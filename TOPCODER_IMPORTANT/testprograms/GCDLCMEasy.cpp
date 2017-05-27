#include <bits/stdc++.h>

#define all(a)           a.begin(),a.end()
#define chng(a,b)       a^=b^=a^=b;
#define clr(y,z)        memset(y,z,sizeof(y))
#define cntbit(mask)     __builtin_popcount(mask)
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define fr(i,a,b)       for(i=a;i<=b;i++)
#define inf             (1e9)
#define mod             1000000007
#define ll              long long
#define oo              (1<<30)
#define pb              push_back
#define PI              3.141592653589793
#define pi              (2*acos(0))
#define pp              pop_back
#define rev(a)          reverse(all(a));
#define SIZE(s)         ((int)s.size())
#define saja(a)         sort(all(a))
#define sqr(a)          ((a)*(a))
#define SZ              50005
#define V(a)            vector<(a)>

using namespace std;


class GCDLCMEasy {
public:
    int primes[1232] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197, 5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387, 5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443, 5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507, 5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639, 5641, 5647, 5651, 5653, 5657, 5659, 5669, 5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791, 5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857, 5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939, 5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053, 6067, 6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133, 6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221, 6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301, 6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 6361, 6367, 6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 6481, 6491, 6521, 6529, 6547, 6551, 6553, 6563, 6569, 6571, 6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 6679, 6689, 6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991, 6997, 7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 7109, 7121, 7127, 7129, 7151, 7159, 7177, 7187, 7193, 7207, 7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 7417, 7433, 7451, 7457, 7459, 7477, 7481, 7487, 7489, 7499, 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919, 7927, 7933, 7937, 7949, 7951, 7963, 7993, 8009, 8011, 8017, 8039, 8053, 8059, 8069, 8081, 8087, 8089, 8093, 8101, 8111, 8117, 8123, 8147, 8161, 8167, 8171, 8179, 8191, 8209, 8219, 8221, 8231, 8233, 8237, 8243, 8263, 8269, 8273, 8287, 8291, 8293, 8297, 8311, 8317, 8329, 8353, 8363, 8369, 8377, 8387, 8389, 8419, 8423, 8429, 8431, 8443, 8447, 8461, 8467, 8501, 8513, 8521, 8527, 8537, 8539, 8543, 8563, 8573, 8581, 8597, 8599, 8609, 8623, 8627, 8629, 8641, 8647, 8663, 8669, 8677, 8681, 8689, 8693, 8699, 8707, 8713, 8719, 8731, 8737, 8741, 8747, 8753, 8761, 8779, 8783, 8803, 8807, 8819, 8821, 8831, 8837, 8839, 8849, 8861, 8863, 8867, 8887, 8893, 8923, 8929, 8933, 8941, 8951, 8963, 8969, 8971, 8999, 9001, 9007, 9011, 9013, 9029, 9041, 9043, 9049, 9059, 9067, 9091, 9103, 9109, 9127, 9133, 9137, 9151, 9157, 9161, 9173, 9181, 9187, 9199, 9203, 9209, 9221, 9227, 9239, 9241, 9257, 9277, 9281, 9283, 9293, 9311, 9319, 9323, 9337, 9341, 9343, 9349, 9371, 9377, 9391, 9397, 9403, 9413, 9419, 9421, 9431, 9433, 9437, 9439, 9461, 9463, 9467, 9473, 9479, 9491, 9497, 9511, 9521, 9533, 9539, 9547, 9551, 9587, 9601, 9613, 9619, 9623, 9629, 9631, 9643, 9649, 9661, 9677, 9679, 9689, 9697, 9719, 9721, 9733, 9739, 9743, 9749, 9767, 9769, 9781, 9787, 9791, 9803, 9811, 9817, 9829, 9833, 9839, 9851, 9857, 9859, 9871, 9883, 9887, 9901, 9907, 9923, 9929, 9931, 9941, 9949, 9967, 9973, 10007};
    int GCD[550][1232], LCM[550][1232], GCDfac[1232], LCMfac[1232];

    void factorize(int G, int L)
    {
        int nn = G;

        for (int i = 0; primes[i]<nn; i++)
        {
            if(nn%primes[i]==0)
            {
                int cnt = 0;
                while(nn%primes[i]==0)
                {
                    nn/=primes[i];
                    cnt++;
                }
                GCDfac[i] = cnt;
            }
        }


        nn = L;

        for (int i = 0; primes[i]<nn; i++)
        {
            if(nn%primes[i]==0)
            {
                int cnt = 0;
                while(nn%primes[i]==0)
                {
                    nn/=primes[i];
                    cnt++;
                }
                LCMfac[i] = cnt;
            }
        }
        return;
    }


    bool check(int nn)
    {
        for (int i = 0; i<1232; i++)
            if(GCD[nn][i]<GCDfac[i]) return true;
        for (int i = 0; i<1232; i++)
            if(LCM[nn][i]>LCMfac[i]) return true;
        return false;
    }

    void form(int nn)
    {
        for (int i = 0; i<1232; i++)
            GCD[nn][i]=GCDfac[i];
        for (int i = 0; i<1232; i++)
            LCM[nn][i]=LCMfac[i];
        return;
    }

    bool got[550];
	string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L) {
		for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<1232; j++)
            {
                GCD[i][j] = 0;
                LCM[i][j] = 0;
            }
            got[i] = false;
        }

        for (int i = 0; i<n; i++)
        {
            factorize(G[i],L[i]);
            if(got[ A[i] ] && got[ B[i] ])
            {
                if(check(A[i]) || check(B[i])) return "Not able";
            }
            else
            {
                if(!got[ A[i] ]) form(A[i]);
                if(!got[ B[i] ]) form(B[i]);
                if(check(A[i]) || check(B[i])) return "Not able";
                got[ A[i] ] = got[ B[i] ] = true;
            }
        }

        return "Able";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, vector <int> p4, bool hasAnswer, string p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p4[i];
	}
	cout << "}";
	cout << "]" << endl;
	GCDLCMEasy *obj;
	string answer;
	obj = new GCDLCMEasy();
	clock_t startTime = clock();
	answer = obj->possible(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p5 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p5;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	vector <int> p4;
	string p5;

	{
	// ----- test 0 -----
	p0 = 4;
	int t1[] = {0,1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {6,6,6,6};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {12,12,12,12};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = "Solution exists";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 5;
	int t1[] = {0,1,2,3,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3,4,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {6,6,6,6,6};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {12,12,12,12,12};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = "No solution";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 2;
	int t1[] = {0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {123,123};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {456,789};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = "Solution does not exist";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 2;
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1234};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {5678};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = "Solution does not exist";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 6;
	int t1[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {2,2,3,3,1,2,5,1,5,1,7,7,3,5,7};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {30,42,30,42,210,70,30,210,70,210,42,70,105,105,105};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = "Have solution";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 500;
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10000};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {10000};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = "Have solution";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Your task is to find n positive integers.
// We will label them x[0] through x[n-1].
//
//
//
// We will give you some information about these integers.
// Namely, for some pairs of integers we will tell you both their greatest common divisor (GCD) and their least common multiple (LCM).
//
//
//
// You are given the int n and four vector <int>s: A, B, G, and L.
// These vector <int>s will all have the same number of elements.
// Their meaning is as follows:
// For each valid i, the integers x[ A[i] ] and x[ B[i] ] must have the greatest common divisor G[i] and the least common multiple L[i].
//
//
//
// Return "Solution exists" (quotes for clarity) if there is at least one way to choose x[0] through x[n-1] so that all requirements are satisfied.
// Otherwise, return "Solution does not exist".
//
// DEFINITION
// Class:GCDLCMEasy
// Method:possible
// Parameters:int, vector <int>, vector <int>, vector <int>, vector <int>
// Returns:string
// Method signature:string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L)
//
//
// NOTES
// -The greatest common divisor (GCD) of two positive integers x and y is the largest positive integer z such that z divides x and at the same time z divides y.
// -The least common multiple (LCM) of two positive integers x and y is the smallest positive integer z such that x divides z and at the same time y divides z.
// -For example, the GCD of 10 and 15 is 5, and the LCM of 10 and 15 is 30.
//
//
// CONSTRAINTS
// -n will be between 1 and 500, inclusive.
// -A will contain between 1 and 500 elements, inclusive.
// -A and B will contain the same number of elements.
// -A and G will contain the same number of elements.
// -A and L will contain the same number of elements.
// -Each element in A will be between 0 and n-1, inclusive.
// -Each element in B will be between 0 and n-1, inclusive.
// -For each i, A[i] and B[i] will be different.
// -Each element in G will be between 1 and 10,000, inclusive.
// -Each element in L will be between 1 and 10,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 4
// {0,1,2,3}
// {1,2,3,0}
// {6,6,6,6}
// {12,12,12,12}
//
// Returns: "Solution exists"
//
// We have 4 unknown integers: x[0], x[1], x[2], and x[3].
// The given A, B, G, and L encode the following information:
//
// The GCD of x[0] and x[1] must be 6 and their LCM must be 12.
// The GCD of x[1] and x[2] must be 6 and their LCM must be 12.
// The GCD of x[2] and x[3] must be 6 and their LCM must be 12.
// The GCD of x[3] and x[0] must be 6 and their LCM must be 12.
//
// There are two valid solutions.
// In one of them, x[0] = x[2] = 6 and x[1] = x[3] = 12.
//
// 1)
// 5
// {0,1,2,3,4}
// {1,2,3,4,0}
// {6,6,6,6,6}
// {12,12,12,12,12}
//
// Returns: "No solution"
//
//
//
// 2)
// 2
// {0,0}
// {1,1}
// {123,123}
// {456,789}
//
// Returns: "Solution does not exist"
//
// The LCM of x[0] and x[1] cannot be 456 and 789 at the same time.
//
// 3)
// 2
// {0}
// {1}
// {1234}
// {5678}
//
// Returns: "Solution does not exist"
//
// The LCM of x[0] and x[1] must always be a multiple of their GCD.
//
// 4)
// 6
// {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4}
// {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5}
// {2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7}
// {30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105}
//
//
// Returns: "Have solution"
//
// There is one solution: {6, 10, 14, 15, 21, 35}.
//
// 5)
// 500
// {0}
// {1}
// {10000}
// {10000}
//
// Returns: "Have solution"
//
//
//
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
