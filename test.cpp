#include <bits/stdc++.h>
#include <format>

std::string code = "LMQETXYEAGTXCTUIEWNCTXLZEWUAISPZYVAPEWLMGQWYAXFTCJMSQCADAGT"
                   "XLMDXNXSNPJQSYVAPRIQSMHNOCVAXFV";
// std::string code = "CIALLO";
// std::string code = "WOWZJX";
// [[3, 2], [5, 7]]
// LMQETXYEAGTXCTUIEWNCTXLZEWUAISPZYVAPEWLMGQWYAXFTCJMSQCADAGTXLMDXNXSNPJQSYVAPRIQSMHNOCVAXFV
int cipherM[2][2];
int plainM[2][2];
int KeyM[2][2];
std::vector<std::string> token;
std::vector<std::string> ans;

std::vector<std::string> ref = {"TH", "HE", "IN", "ER", "AN", "RE", "ED", "ON",
                                "ES", "ST", "EN", "AT", "TO", "NT", "HA", "ND",
                                "OU", "EA", "NG", "AS", "OR", "TI", "IS", "ET",
                                "IT", "AR", "TE", "SE", "HI", "OF", "CI"};

std::map<std::string, int> cnt;

int inv(int &a, int m)
{
	std::cerr << "a = " << a << " m = " << m << std::endl;
	a = a % m;
	a += m;
	a %= m;
	// a = 17;
	for (int x = 1; x < m; x++) {
		// std::cerr << a << ' ' << x << ' ' << (a * x) % m << '\n';
		if ((a * x) % m == 1) {
			return x;
		}
	}
	return -1; // No modular inverse if this point is reached
}

int main()
{
	int n = code.length();
	std::cerr << "\033[31m" << "size " << n << "\033[0m\n";
	for (int i = 0; i < n; i += 2) {
		token.push_back(code.substr(i, 2));
	}
	for (const auto &t : token) {
		cnt[t]++;
	}
	std::vector<std::pair<std::string, double>> freq;
	for (const auto &[k, v] : cnt) {
		freq.push_back({k, v});
	}
	std::sort(freq.begin(), freq.end(),
	          [](const auto &a, const auto &b) { return a.second > b.second; });
	auto top2 = std::vector<std::string>{freq[0].first, freq[1].first};
	for (int i = 0; i < ref.size(); i++) {
		for (int j = 0; j < ref.size(); j++) {
			cipherM[0][0] = top2[0][0] - 'A';
			cipherM[0][1] = top2[1][0] - 'A';
			cipherM[1][0] = top2[0][1] - 'A';
			cipherM[1][1] = top2[1][1] - 'A';

			plainM[0][0] = ref[i][0] - 'A';
			plainM[0][1] = ref[j][0] - 'A';
			plainM[1][0] = ref[i][1] - 'A';
			plainM[1][1] = ref[j][1] - 'A';

			int inv_plainM[2][2];

			inv_plainM[0][0] = cipherM[0][0];
			inv_plainM[0][1] = 26 - cipherM[0][1];
			inv_plainM[1][0] = 26 - cipherM[1][0];
			inv_plainM[1][1] = cipherM[1][1];

			int det =
			    (plainM[0][0] * plainM[1][1] - plainM[0][1] * plainM[1][0]) %
			    26;
			if (det < 0)
				det += 26;
			int det_inv = inv(det, 26);
			if (det_inv == -1)
				continue;

			inv_plainM[0][0] = det_inv * inv_plainM[0][0] % 26;
			inv_plainM[0][1] = det_inv * inv_plainM[0][1] % 26;
			inv_plainM[1][0] = det_inv * inv_plainM[1][0] % 26;
			inv_plainM[1][1] = det_inv * inv_plainM[1][1] % 26;

			KeyM[0][0] = (cipherM[0][0] * inv_plainM[0][0] +
			              cipherM[0][1] * inv_plainM[1][0]) %
			             26;
			KeyM[0][1] = (cipherM[0][0] * inv_plainM[0][1] +
			              cipherM[0][1] * inv_plainM[1][1]) %
			             26;
			KeyM[1][0] = (cipherM[1][0] * inv_plainM[0][0] +
			              cipherM[1][1] * inv_plainM[1][0]) %
			             26;
			KeyM[1][1] = (cipherM[1][0] * inv_plainM[0][1] +
			              cipherM[1][1] * inv_plainM[1][1]) %
			             26;

			std::cerr << "\033[38:5:33m" << KeyM[0][0] << ' ' << KeyM[0][1]
			          << '\n'
			          << KeyM[1][0] << ' ' << KeyM[1][1] << std::endl;

			int inv_KeyM[2][2];
			int det_KeyM =
			    ((KeyM[0][0] * KeyM[1][1] - KeyM[0][1] * KeyM[1][0]) % 26 +
			     26) %
			    26;
			int det_KeyM_inv = inv(det_KeyM, 26);
			std::cerr << "\033[32m" << "inv " << det_KeyM_inv << "\033[0m\n";
			if (det_KeyM_inv == -1)
				continue;
			inv_KeyM[0][0] = KeyM[0][0];
			inv_KeyM[0][1] = 26 - KeyM[0][1];
			inv_KeyM[1][0] = 26 - KeyM[1][0];
			inv_KeyM[1][1] = KeyM[1][1];

			inv_KeyM[0][0] = (inv_KeyM[0][0] * det_KeyM_inv) % 26;
			inv_KeyM[0][1] = (inv_KeyM[0][1] * det_KeyM_inv) % 26;
			inv_KeyM[1][0] = (inv_KeyM[1][0] * det_KeyM_inv) % 26;
			inv_KeyM[1][1] = (inv_KeyM[1][1] * det_KeyM_inv) % 26;

			std::string result;
			for (int i = 0; i < token.size(); i++) {
				int c00 = token[i][0] - 'A';
				int c01 = token[i][1] - 'A';

				int p00 = (inv_KeyM[0][0] * c00 + inv_KeyM[0][1] * c01) % 26;
				int p01 = (inv_KeyM[1][0] * c00 + inv_KeyM[1][1] * c01) % 26;

				result += (char)(p00 + 'A');
				result += (char)(p01 + 'A');
			}
			ans.push_back(result);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << std::endl;
	}
	return 0;
}