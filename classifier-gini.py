
# coding: utf-8

# In[32]:


import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix 
from sklearn import metrics
from sklearn.metrics import classification_report 


# In[33]:


col_names=['age','job','marital','education','default','balance','housing','loan','contact','day','month','duration','compaign','pdays','previous','poutcome']
banks=pd.read_excel("C:\\Users\\User\\Desktop\\bankdata.xlsx")

banks.head()


# In[34]:


feature_names=[' age', ' job ', ' marital ', ' education ', ' default ', ' balance ',
       ' housing ', ' loan ', ' contact ', ' day ', ' month ', ' duration ',
       ' campaign ', ' pdays ', ' previous ', ' poutcome ',]


# In[35]:


X=banks[feature_names]
z=banks.Y
X_train, X_test, z_train, z_test =train_test_split(X,z,test_size=0.3,random_state=1)


# In[39]:




clf_gini = DecisionTreeClassifier(criterion = "gini", 
            random_state = 100,max_depth=3, min_samples_leaf=5) 
   
clf_gini=clf_gini.fit(X_train, z_train)
      


# In[40]:


#def prediction(X_test, clf_object): 

z_pred = clf_gini.predict(X_test) 
print("Predicted values:") 
print(z_pred) 
#return z_pred


# In[41]:


#def cal_accuracy(z_test, z_pred): 
      
print("Confusion Matrix: ", 
        confusion_matrix(z_test, z_pred)) 
    
#print ("Accuracy : ", 
    #accuracy_score(z_test,z_pred)*100)
print("accuracy score is",metrics.accuracy_score(z_test,z_pred))
      
print("Report : ", 
    classification_report(z_test, z_pred)) 

