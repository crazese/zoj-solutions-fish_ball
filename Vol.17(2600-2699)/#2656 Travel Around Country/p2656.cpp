// ��������Ծ�������̫Ư����
// 1.85s 468K 1AC 
// ����֪��������һ�ģ���ô�������� < 1s ��

// �㷨���£�ʵ���ϣ��������� O �� U��˵���˾���һ�� O - U
// ����ÿ��վ�������仯��ֻҪ��ĳ��վ��ʼֱ����������������Ϊ������
// �ӵ�һ����ʼ�ۼӣ�ÿ���ۼӵ�������ʱ�򣬽��ӵ����������ͳ��б��ѹջ
// ��������󣬵õ��Ķ�ջ���Ǵ�ĳ����������վ��ʼ���ߵ���Զ��һ�����ķѵ�����
// ע�⣬�����ķ�ʽѹջ������ǿ��ܵĻ����Ǿ�ֻ��ջ��������
// Ȼ�󽫶�ջ����Ԫ�ض�������������Ǹ�����ô�ó������о���ջ��ָ���ĳ���
// ���򣬲����� 

#include <cstdio>

int main() {
	int	N,	x1,	x2;
	int	fuel[10000],	top,	city[10000];
	while( scanf( "%d", &N ) != EOF ) {
		fuel[0] = city[0] = top = 0;
		for( int i = 0; i < N; i++ ) {
			scanf( "%d%d", &x1, &x2 );
			fuel[top] += ( x1 - x2 );
			if( fuel[top] < 0 || i == N - 1 ) {
				fuel[++top] = 0;
				city[top] = i + 1;
			}
		}
		for( int i = 1; i < top; i++ ) fuel[i] += fuel[i - 1];
		if( fuel[top - 1] < 0 ) printf( "impossible\n" );
		else			printf( "%d\n", city[top - 1] );
	}
}