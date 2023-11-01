# Generating Docs

  
## Generating Docs Locally
Follow these steps to generate a new set of docs

### First Time
1. Install sphinx
```php
pip install sphinx
```
2. Install the RTD theme
```php
pip install sphinx-rtd-theme
```
### (Re)generating the docs
1. Within the ./docs folder run:
```php
make html
```
## Generating Docs In a Python Virtual Environment

### Create a new Virtual Environment
Within your project folder, run:
```php
python -m venv NAME_ME
```
This creates  a new virtual environment, "NAME_ME". Then run:
```php
source NAME_ME/bin/activate
```
This activates the venv called NAME_ME. if it works you’ll see the env name appear to the left of your terminal line. Next, run:
```php
pip install sphinx
pip install sphinx-rtd-theme
pip install -r requirements.txt
```
This should install all required packages. To create a new requirements.txt file with all of the current packages, run:
```php
pip freeze > requirements.txt
```
**To deactivate the virtual environment**, simple run:
```php
deactivate
```

More information on Python Virtual Environments can be found here:
https://realpython.com/python-virtual-environments-a-primer/