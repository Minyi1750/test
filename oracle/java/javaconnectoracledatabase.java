package oraclejavademo;

import java.sql.*;
import oracle.jdbc.*;
import oracle.jdbc.pool.OracleDataSource;

/*
 * java application connect oracle database.
 * */

public class JDBCVersion {

	public static void main(String[] args) throws SQLException
	{
		// TODO Auto-generated method stub
		System.out.print("Hello world\n");
		testConnectOracle();

	}
	
	
	public static void testConnectOracle() throws SQLException {
		
		OracleDataSource ods = new OracleDataSource();
		ods.setURL("jdbc:oracle:thin:biz/biz@192.168.60.30:1521/ORCL");
		Connection conn = ods.getConnection();
		
		//cretae oracle databasemetdata object
		DatabaseMetaData meta = conn.getMetaData();
		
		//get driver info;
		System.out.println("JDBC driver version is " + meta.getDriverMajorVersion());
		
		
		//执行查詢
		Statement stmt = conn.createStatement();
		
		String sql = " select  a.USER_ID,a.USERNAME, a.PASSWORD, a.ACCOUNT_STATUS  "
				+" from dba_users a "
				+" where a.ACCOUNT_STATUS = 'OPEN' ";
		
		System.out.println("\nExecuting query: " + sql);
		ResultSet rset = stmt.executeQuery(sql);
		
		while (rset.next()) {
			System.out.println( rset.getString(1) + " " + 
			rset.getString(2) + " " +
			rset.getString(3) + " " +
			rset.getString(4)
			);
		}
		
		
		conn.close();
	}
	


}
