from datetime import datetime, timedelta

start_date = datetime(2014, 4, 2)
N = int(input())
anniversary_date = start_date + timedelta(days=N-1)
print(anniversary_date.strftime('%Y-%m-%d'))
