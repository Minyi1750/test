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
--查看数据库的参数, 默认表空间
SELECT * FROM database_properties a 
where A.PROPERTY_NAME like  '%TEMP%';
-----------------------------
--oracle自动删除表空间以及和表空间关联的数据文件。
DROP TABLESPACE TEMP INCLUDING CONTENTS AND DATAFILES;



/*
UNIFORM specifies that the tablespace is managed with uniform extents of SIZE
bytes.The default SIZE is 1 megabyte. All extents of temporary tablespaces are of
uniform size, so this keyword is optional for a temporary tablespace. However,
you must specify UNIFORM in order to specify SIZE. You cannot specify UNIFORM for
an undo tablespace.

UNIFORM指定了 被管理的表空间有统一的extents大小。默认是1M。所有的临时表空间的extents是统一的大小，
所以这个关键字是可选的对于临时表空间而言。除非，你必须指定其他的size。在创建undo表空间时，不用指定。
*/
CREATE TEMPORARY TABLESPACE TEMP TEMPFILE 
  '/oracle/ora11/oradata/ora11g/temp01.dbf' SIZE 32767M AUTOEXTEND ON NEXT 640K MAXSIZE UNLIMITED,
  '/oradataa/temp02.dbf' SIZE 5120M AUTOEXTEND ON NEXT 1024M MAXSIZE UNLIMITED
TABLESPACE GROUP ''
EXTENT MANAGEMENT LOCAL 
UNIFORM SIZE 1M;