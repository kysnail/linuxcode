## Git submodules in N easy steps
Git has something called submodule support. This allows you to specify one or more other repositories within another - a bit like `svn:external` (except tricker, but more powerful of course :)).

The [git user manual](http://schacon.github.com/git/user-manual.html#submodules) describes submodules but it took me a while to figure it out, so I'm hoping these examples will help others (and me again when I forget and find my own page when googling about it :)).

These examples deal with `your_project` and the project you'll be adding as a submodule, `other_project`.

### Adding a submoudle to your_project

	$ git submodule add git@git.example.com:other_project.git other_project
	Initialized empty Git repository in /home/john/dev/your_project/other_project/.git/ 
	remote: Counting objects: 59, done. 
	remote: Compressing objects: 100% (59/59), done. 
	remote: Total 59 (delta 22), reused 0 (delta 0) 
	Receiving objects: 100% (59/59), 8.33 KiB, done. 
	Resolving deltas: 100% (22/22), done. 

This clones `other_project` and set up the .gitmodules config to your_project and adds them both ready to be committed. You'll notice that the other_project directory is added, not all the files within. Git just record the commit id from the other_project repository and uses that when clning - a bit like a tag.

	$ git status
	# new file: .gitmodules 
	# new file: other_project 

So now commit those changes:

	$ git commit .gitmodules other_project -m "Added other_project submodule" 
	$ git push 


### Cloning a tree with submodules
Git doesn't automatically fetch all your submodules, so you need to do the following after cloning your tree:

	$ git submodule init 
	Submodule 'other_project' (git@git.example.com:other_project.git) registered for path 'other_project' 
	$ git submodule update 
	Initialized empty Git repository in /home/john/dev/your_project/other_project/.git/ 
	remote: Counting objects: 59, done. 
	Receiving objects: 100% (59/59), 8.33 KiB, done.bjects: 91% (54/59) 
	Resolving deltas: 100% (22/22), done. 
	remote: Compressing objects: 100% (59/59), done. 
	remote: Total 59 (delta 22), reused 0 (delta 0) 
	Submodule path 'other_project': checked out '6d5ca374208715501832eb33ed6a70022a3bb60c' 

### Updating a submodule
So somebody pused some updates to other_project and you want them in your_project:

	$ cd other_project 
	$ git pull origin master 
	Updating 6d5ca37..235996d Fast forward 5 files changed, 100 insertions(+), 10 deletions(-) 
	$ cd .. 
	$ git add other_project 
	$ git commit otherproject -m " Updated other_project submodule to latest HEAD" 

If you a particular commit rather than the head of master, then just specify that commit id on pull (instead of master). If you want the head of a particular branch then specify that branch name instead of master.

It is important **not to having a trailing slash** when you add other_project as this will treat it as a normal directory, adding all the files within it to your_project and forgetting about it's submodule status.

### Making changes to a submodule within your_project
To make changes to other_project within your_project tree, you need explicitly checkout a branch first:

	$ cd other_project 
	$ git checkout master ...make your changes... 
	$ git commit -a -m "Fixed a bug" 
	$ git push 
	$ cd .. 
	$ git add other_project 	
	$ git commit -m "Updated other_project" 

You need to remeber to push changes to other_project before you push your_project else other's won't be able t oclone your_project properly as it wll reference commits to other_project that haven't been published yet!


**Refs**

 * [Git submodules in N easy steps](http://johnleach.co.uk/words/323/git-submodules-in-n-easy-steps)
