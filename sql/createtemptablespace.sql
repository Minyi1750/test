select * from dba_temp_files;
select * from v$tablespace where  name like '%TEMP%';--temp temp02

select * from user_tablespace;
select * from v$datafile;
select * from v$tempfile;
--CF 18-9 
DROP TABLESPACE temp INCLUDING CONTENTS AND DATAFILES;
--ORA-01144: File size (4194304 blocks * 8192 ) exceeds maximum of 4194303 * 8192 blocks

CREATE TEMPORARY TABLESPACE temp02 TEMPFILE '/oradataa/temp01.dbf' 
SIZE 32767M
AUTOEXTEND ON NEXT 5120M MAXSIZE UNLIMITED
EXTENT MANAGEMENT LOCAL; 
ALTER DATABASE DEFAULT TEMPORARY TABLESPACE temp02;
--�鿴���ݿ�Ĳ���, Ĭ�ϱ�ռ�
SELECT * FROM database_properties a 
where A.PROPERTY_NAME like  '%TEMP%';
-----------------------------
--oracle�Զ�ɾ����ռ��Լ��ͱ�ռ�����������ļ���
DROP TABLESPACE TEMP INCLUDING CONTENTS AND DATAFILES;



/*
UNIFORM specifies that the tablespace is managed with uniform extents of SIZE
bytes.The default SIZE is 1 megabyte. All extents of temporary tablespaces are of
uniform size, so this keyword is optional for a temporary tablespace. However,
you must specify UNIFORM in order to specify SIZE. You cannot specify UNIFORM for
an undo tablespace.

UNIFORMָ���� ������ı�ռ���ͳһ��extents��С��Ĭ����1M�����е���ʱ��ռ��extents��ͳһ�Ĵ�С��
��������ؼ����ǿ�ѡ�Ķ�����ʱ��ռ���ԡ����ǣ������ָ��������size���ڴ���undo��ռ�ʱ������ָ����
*/
CREATE TEMPORARY TABLESPACE TEMP TEMPFILE 
  '/oracle/ora11/oradata/ora11g/temp01.dbf' SIZE 32767M AUTOEXTEND ON NEXT 640K MAXSIZE UNLIMITED,
  '/oradataa/temp02.dbf' SIZE 5120M AUTOEXTEND ON NEXT 1024M MAXSIZE UNLIMITED
TABLESPACE GROUP ''
EXTENT MANAGEMENT LOCAL 
UNIFORM SIZE 1M;