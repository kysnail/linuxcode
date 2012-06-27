## Mastering JSON (JavaScript Object Notation)
Widely hailed as the successor to XML in the browser, JSON aspires to be nothing more than a simple, and elegant data format for the exchange of information between the browser and server; and in doing this simple task it will usher in the next verion the World Wide Web itself.

### The Object : An Introduction
Behold, an Object...

	var MyFirstObject = {};

It may not look like much, but those squiggly braces have the potential to record every bit of information humanity has ever gathered, and express the most complex programs computer scientists can dream up. In fact, JavaScript itself is stored inside of a set of squiggly braces just like that, as are all of its primitive data types -- strings, numbers, arrays, dates, regular expressions, they're all objects and they all started out just like myFirstObject.

### Creating A New Object
The old way to create a new object was to use the "new" keyword.

	var myJSON = new Object();

This method has been `deprecated` now in favor of simply defining an empty object with squiggly braces...

	var myJSON = {};

### Objects as Data
At its most base level a JavaScript Object is a very flexible and robust data format expressed as "name/value pairs". That is, an object holds a name which is an object's property -- think of it as a plain old variable name that's attached to the object name,. And the object holds the value of that name. Here's an example...

	var myFirstJSON = {
				"firstName" : "John",
				"lastName"  : "Doe",
				"age"	    : 23
							};

	document.writeln(myFirstJSON.firstName);	// Outputs John
	document.writeln(myFirstJSON.lastName);		// Outputs Doe
	document.writeln(myFirstJSON.age);		// Outputs 23

This object has 3 properties or name/value pairs. The name is a string -- in our example, firstName, lastName, and age. The value can be any JavaScript object (and remember everything in JavaScript is an object so the value can be a string, number, array, function, even other Objects) -- In this example our values are John, Doe, and 23. John and Doe are strings but age is a number and as you can see this is not a problem.

This data format is called JSON for JavaScript Object Notation. What makes it particularly powerful is that since the value can be any data type, you can store other arrays and other objects, nesting them as deeply as you need.

Here is an example of a somewhat complex JSON structure ...

	var employees = {
				"accounting" : 	[	// accounting is an array in employees.
							{
								"firstName" : "John",	// First element
								"lastName"  : "Doe",
								"age:	    : 23
							},

							{
								"firstName" : "Mary",	// Second element
								"lastName"  : "Smith",
								"age:	    : 32
							},
						],	// End "accounting" array.
				"sales" : 	[	// Sales is another array in employees.
							{
								"firstName" : "Sally",	// First element
								"lastName"  : "Green",
								"age:	    : 23
							},

							{
								"firstName" : "Jim",	// Second element
								"lastName"  : "Galley",
								"age:	    : 41
							},
						],	// End "sales" array.
			} // End Employees

Here employees is an object. That object has two properties or name/value pairs. Accounting is an array which holds two JSON objects showing the name and age of 2 employees. Likewise sales is also an array which holds two JSON objects showing the name and age of the two employees who work in sales. All of this data exists within the employees object. There are several different ways to access this data.


