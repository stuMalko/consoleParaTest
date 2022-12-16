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
//	int fd = fileno(stdin); //int fileno(FILE *stream)用来取得参数stream指定的文件流所使用的文件描述符 
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
//	int fd = fileno(stdin); //int fileno(FILE *stream)用来取得参数stream指定的文件流所使用的文件描述符 
//	char s[256] = { 0 }, name[256] = { 0 };
//	snprintf(s, 255, "/proc/%d/fd/%d", getpid(), fd);
//	/*
//	 *
//	 *
//	 *
//	 * 　　int snprintf(char *str, size_t size, const char *format, ...);
//	 * 　　将可变个参数(...)按照format格式化成字符串，然后将其复制到str中，
//	 *     返回写入str中的字符串的长度，所以可以利用snprintf函数来提前获取需要的内存空间大小，按如下格式调用：
//	 * 　　int ret = snprintf(NULL,0,"%s%d","test", 123); //结果ret为7即设置第一二个参数分别为NULL和0，获得的ret就为实际需要的内存空间大小,
//			   这对于打印长度不可预知的字符串比较有效，便于我们合理分配空间，既不浪费又不产生截断。
//	 * 　　(1) 如果格式化后的字符串长度 < size，则将此字符串全部复制到str中，并给其后添加一个字符串结束符('\0')；
//	 * 　　(2) 如果格式化后的字符串长度 >= size，则只将其中的(size-1)个字符复制到str中，并给其后添加一个字符串结束符('\0')
//	 * 　　函数返回值:若成功则返回欲写入的字符串长度，若出错则返回负值
//	 *
//	 *
//	 */
//
//	readlink(s, name, 255);
//	/*
//	readlink()会将参数path的符号链接内容存储到参数buf所指的内存空间，返回的内容不是以\000作字符串结尾，但会将字符串的字符数返回，
//	这使得添加\000变得简单。若参数bufsiz小于符号连接的内容长度，过长的内容会被截断，如果 readlink 第一个参数指向一个文件而不是符号链接时，
//	readlink 设 置errno 为 EINVAL 并返回 -1。 readlink()函数组合了open()、read()和close()的所有操作。
//	*/
//
//	printf("%s\n", name);
//	return 0;
//}