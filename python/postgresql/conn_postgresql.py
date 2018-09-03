#encoding='utf-8'
'''
将PostgreSQL的数据导出为csv文件
'''
import psycopg2
import csv
tablenamelist = [
	'testtable1',
	'testtable2'
	'testtable3'
]
conn = psycopg2.connect(host='192.168.60.30', port=5359, user='testuser', password='testuserpasword', dbname='testdb')
cur = conn.cursor()
for table in tablenamelist:
    sql = '''select  * from "testdb"."%s" limit 300; ''' % table
    print sql
    cur.execute(sql)
    with open('D:/temp/lib/%s.csv' % table, 'wb') as csvfile:
        spamwriter = csv.writer(csvfile, delimiter=',', quotechar='\'', quoting=csv.QUOTE_ALL)
        title = [col.name for col in cur.description]
        spamwriter.writerow(title)
        for line in cur:
            spamwriter.writerow(line)

print "End database."
cur.close()
conn.close()