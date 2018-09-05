# -*- coding: utf-8 -*-
"""
Created on Wed Sep  5 23:13:31 2018

@author: Minyi
"""
'''
The Google Finance API has not been stable since late 2017. Requests seem
to fail at random. Failure is especially common when bulk downloading.
'''
import pandas as pd
pd.core.common.is_list_like = pd.api.types.is_list_like
import pandas_datareader.data as web
import datetime
start = datetime.datetime(2010, 1, 1)
end = datetime.datetime(2013, 1, 27)
f = web.DataReader('F', 'google', start, end)
f.ix['2010-01-04']