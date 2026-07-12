# 1. Define the masks (usually as constants)
READ    = 1  # 0001
WRITE   = 2  # 0010
EXECUTE = 4  # 0100
DELETE  = 8  # 1000

# 2. Start with no permissions (all bits are 0)
user_permissions = 0 

# 3. SET flags 
user_permissions = user_permissions | READ | EXECUTE 
# In binary: 0001 | 0100 = 0101 (which equals 5 in decimal)

# 4. CHECK flags 
if user_permissions & EXECUTE:
    print("User can execute!")

# Does the user have Delete permission?
if user_permissions & DELETE:
    print("User can delete!")
else:
    print("Access denied for delete.")