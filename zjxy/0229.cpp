/*
 * 0229-����Ǯ
 * �ٶ������������ֲ�ͬ����Ӳ�ң�ϣ���ڸ���Ҫ�����Ǯ���Լ����õ�Ӳ����������֮�󣬿����ҳ���������ٵ�Ӳ�Ҹ����ķ�����
 * ˼·����̬�滮
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> func0229() {
	int arr[] = {1, 2, 5, 10, 50};
	int amount = 38;
	vector<int> coins(begin(arr), end(arr));
	vector<int> dp(amount + 1, 0);

    for (int i = 1; i < amount + 1; i++) {
        dp[i] = amount + 1;
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
        
    vector<int> ans;
    int pre = amount;
    int pre_coins = dp[amount];
    for (int i = amount; i >= 0; i--) {
        if (dp[i] == pre_coins - 1) {
            pre_coins --;
            ans.push_back(pre - i);
            pre = i;
        }
    }

    return ans;

}

int main() {
	func0229();
	system("pause");
	return 0;
}
