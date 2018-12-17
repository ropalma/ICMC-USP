### Learning Git

 - References
    - [Magia Git Ben Lynn](http://www-cs-students.stanford.edu/~blynn/gitmagic/intl/pt_br/book.html)

 - Git clone repository
    ```
    $ git clone url-here
    ```
 - Init Git Repository
    ```
	$ git init
    ```
 - Add all items to git commit repository
    ```
    $ git add .
    ```
 - See all the files added in repository
    ```
    $ git status
    ```
 - Add some items to git commit repository
    ```
    $ git add README.md test.txt ...
    ```
 - Commit Git files
    ```
    $ git commit -m 'comments about commit here'
    ```
 - Add remote repository
    ```
    $ git remote add name-of-origin url-repository-here
    ```
 - Create a new branch
    ```
    $ git checkout -b name-of-new-branch
    ```
 - See all git branchs
    ```
    $ git branch
    ```
 - Commit all files in MASTER branch to repository
    ```
    $ git push name-of-origin master 
    ```
 - Commit all files NAME-OF-BRANCH to repository
    ```
    $ git push name-of-origin name-of-branch
    ```
 -  See Git log
    ```
    $ git log
    ```
 - Change Branch
    ```
    $ git checkout name-branch-to-change
    ```
 - Undo all git add
    ```
    $ git reset .
    or
    $ git reset file-to-undo
    ```
 - Git clone a specific branch in a github repo
    ```
    $ git clone -b {branch} git@github.com:{repo_name}.git
    ```
