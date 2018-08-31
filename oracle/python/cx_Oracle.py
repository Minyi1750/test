
# coding: utf-8

# In[1]:


#python连接oracles数据库
import cx_Oracle


# In[16]:


conn = cx_Oracle.connect('biz', 'biz', '192.168.60.30:1521/ORCL')


# In[17]:


cursor = conn.cursor()


# In[18]:


sql = '''
    select  a.USER_ID,a.USERNAME, a.PASSWORD, a.ACCOUNT_STATUS 
    from dba_users a
    where a.ACCOUNT_STATUS = 'OPEN'
'''


# In[19]:


#执行sql, 并且输出
for line in cursor.execute(sql):
    print(line)


# In[20]:


cursor.close()


# In[21]:


conn.close()

