REM ��������Ŀ¼�е�����C++�ļ���Astyle���д�����������
REM ����Astyle����λ�úͲ���
@echo off
REM ѭ������Ŀ¼
for /r . %%f in (*.cpp;*.c) do astyle --style=kr "%%f"
for /r . %%f in (*.hpp;*.h) do astyle --style=kr "%%f"
REM ɾ�����е�astyle�����ļ�
for /r . %%f in (*.orig) do del "%%f"
pause