/*
    蓄水池采样(Reservoir Sampling)
    大数据流中的随机抽样问题：
    当内存无法加载全部数据时，如何从包含未知大小的数据流中随机选取k个数据
    并且要保证每个数据被抽取到的概率相等。
 */
# define K 10000 // 假设K为10000

int n = 0; //记录读取的数据量
int reservoir[K];
int p;

while(streamHasData()) {
    int x = readNumber();
    if(n < k) reservoir[n++] = x;
    else {
        p = random(++n);
        if(p < K) reservoir[p] = x;
    }
}