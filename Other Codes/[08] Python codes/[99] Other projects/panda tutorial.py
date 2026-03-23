import pandas as pd

mydataset = {
    'cars': ["BMw", "volvo", "Ford", "TVS"], 
    'passings': [3,7,2, 8],
    'breaking': [32, 12, 4534, 12]
}

myvar = pd.DataFrame(mydataset)

print(myvar)