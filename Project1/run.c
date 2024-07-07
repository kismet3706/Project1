#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


/*
* 可变参数：计算平均数
* @parm num_args 参数的数量
* @parm ...可变参数列表，int a, int b ,int c......
* @return 平均数
*/

double average(int num_args, ...);


int main(void) {

	printf("Ave 1,2,3,4 = %.2f\n", average(4, 5, 2, 3, 4));
	/*printf自带的定义就是有...的
	_CRT_STDIO_INLINE int __CRTDECL printf(
		_In_z_ _Printf_format_string_ char const* const _Format,
		...)
		*/
	//日志
	//snprintf
	return EXIT_SUCCESS;
}

double average(int num_args, ...) {
	double sum = 0.0;

	va_list args;

	va_start(args, num_args);

	for (size_t i = 0; i < num_args; i++)
	{
		sum += va_arg(args, int);	//va_start会自动获取下一个参数
	}

	va_end(args);

	return num_args > 0 ? sum / num_args : 0;
}