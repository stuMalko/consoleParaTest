//#include<iostream>
//#include<stdio.h>
//#include <unistd.h>
//
//using namespace std;
//
//int main(int argc, char* argv[]) {
//
//	long long secTimeout = atoll(argv[1]);
//	int randSeed = atoi(argv[2]);
//	//char* paraWithFile = argv[3];
//
//	int fd = fileno(stdin); //int fileno(FILE *stream)����ȡ�ò���streamָ�����ļ�����ʹ�õ��ļ������� 
//	char s[256] = { 0 }, name[256] = { 0 };
//	snprintf(s, 255, "/proc/%d/fd/%d", getpid(), fd);
//	readlink(s, name, 255);
//	printf("%s\n", name);
//
//	cout << secTimeout << ", " << randSeed << ", " << argv[3] << endl;
//
//	return 0;
//}

//#include <unistd.h>
//#include <stdio.h>
//
//int main(int argc, char** argv) {
//	int fd = fileno(stdin); //int fileno(FILE *stream)����ȡ�ò���streamָ�����ļ�����ʹ�õ��ļ������� 
//	char s[256] = { 0 }, name[256] = { 0 };
//	snprintf(s, 255, "/proc/%d/fd/%d", getpid(), fd);
//	/*
//	 *
//	 *
//	 *
//	 * ����int snprintf(char *str, size_t size, const char *format, ...);
//	 * �������ɱ������(...)����format��ʽ�����ַ�����Ȼ���临�Ƶ�str�У�
//	 *     ����д��str�е��ַ����ĳ��ȣ����Կ�������snprintf��������ǰ��ȡ��Ҫ���ڴ�ռ��С�������¸�ʽ���ã�
//	 * ����int ret = snprintf(NULL,0,"%s%d","test", 123); //���retΪ7�����õ�һ���������ֱ�ΪNULL��0����õ�ret��Ϊʵ����Ҫ���ڴ�ռ��С,
//			   ����ڴ�ӡ���Ȳ���Ԥ֪���ַ����Ƚ���Ч���������Ǻ������ռ䣬�Ȳ��˷��ֲ������ضϡ�
//	 * ����(1) �����ʽ������ַ������� < size���򽫴��ַ���ȫ�����Ƶ�str�У�����������һ���ַ���������('\0')��
//	 * ����(2) �����ʽ������ַ������� >= size����ֻ�����е�(size-1)���ַ����Ƶ�str�У�����������һ���ַ���������('\0')
//	 * ������������ֵ:���ɹ��򷵻���д����ַ������ȣ��������򷵻ظ�ֵ
//	 *
//	 *
//	 */
//
//	readlink(s, name, 255);
//	/*
//	readlink()�Ὣ����path�ķ����������ݴ洢������buf��ָ���ڴ�ռ䣬���ص����ݲ�����\000���ַ�����β�����Ὣ�ַ������ַ������أ�
//	��ʹ�����\000��ü򵥡�������bufsizС�ڷ������ӵ����ݳ��ȣ����������ݻᱻ�ضϣ���� readlink ��һ������ָ��һ���ļ������Ƿ�������ʱ��
//	readlink �� ��errno Ϊ EINVAL ������ -1�� readlink()���������open()��read()��close()�����в�����
//	*/
//
//	printf("%s\n", name);
//	return 0;
//}