Ext.data.JsonP.class_system({
  "guide": "<h1>Ext JS 4 Class System</h1>\n\n<hr />\n\n<p>For the first time in its history, <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS went through a huge refactoring from the ground up with the new class system. The new architecture stands behind almost every single class written in <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS 4.x, hence it's important to understand it well before you start coding.</p>\n\n<p>This manual is intended for any developer who wants to create new or extend existing classes in <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS 4.x. It's divided into 3 main sections:</p>\n\n<ul>\n<li>Section I: \"Overview\" explains the need for a robust class system</li>\n<li>Section II: \"Naming Conventions\" discusses the best practices for naming classes, methods, properties, variables and files.</li>\n<li>Section III: \"Hands-on\" provides detailed step-by-step code examples</li>\n<li>Section IV: \"Errors Handling &amp; Debugging\" gives useful tips &amp; tricks on how to deal with exceptions</li>\n</ul>\n\n\n<h2>I. Overview</h2>\n\n<hr />\n\n<p>Ext JS 4 ships with more than 300 classes. We have a huge community of more than 200,000 developers to date, coming from various programming backgrounds all over the world. At that scale of a framework, we face a big challange of providing a common code architecture that is:</p>\n\n<ul>\n<li>familiar and simple to learn</li>\n<li>fast to develop, easy to debug, painless to deploy</li>\n<li>well-organized, extensible and maintainable</li>\n</ul>\n\n\n<p>JavaScript is a classless, <a href=\"http://en.wikipedia.org/wiki/Prototype-based_programming\">prototype-oriented</a> language. Hence by nature, one of the language's most powerful features is flexibility. It can get the same job done by many different ways, in many different coding styles and techniques. That feature, however, comes with the cost of unpredictability. Without a unified structure, JavaScript code can be really hard to understand, maintain and re-use.</p>\n\n<p><a href=\"http://en.wikipedia.org/wiki/Class-based_programming\">Class-based</a> programming, on the other hand, still stays as the most popular model of OOP. <a href=\"http://en.wikipedia.org/wiki/Category:Class-based_programming_languages\">Class-based languages</a> usually require strong-typing, provide encapsulation, and come with standard coding convention. By generally making developers adhere to a large set of principle, written code is more likely to be predictable, extensible and scalable over time. However, they don't have the same dynamic capability found in such language as JavaScript.</p>\n\n<p>Each approach has its own pros and cons, but can we have the good parts of both at the same time while concealing the bad parts? The answer is yes, and we've implemented the solution in <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS 4.</p>\n\n<h2>II. Naming Conventions</h2>\n\n<h3>1) Classes</h3>\n\n<ul>\n<li><p>Class names may only contain <strong>alphanumeric</strong> characters. Numbers are permitted but are discouraged in most cases, unless they belong to a technical term. Do not use underscores, hyphens, or any other nonalphanumeric character. For example:</p>\n\n<ul>\n<li><code>MyCompany.useful_util.Debug_Toolbar</code> is discouraged</li>\n<li><code>MyCompany.util.Base64</code> is acceptable</li>\n</ul>\n</li>\n<li><p>Class names should be grouped into packages where appropriate and properly namespaced using object property dot-notation (.). At the minimum, there should be one unique top-level namespace followed by the class name. For example:</p>\n\n<ul>\n<li><code>MyCompany.data.CoolProxy</code></li>\n<li><code>MyCompany.Application</code></li>\n</ul>\n</li>\n<li><p>The top-level namespaces and the actual class names should be in CamelCased, everything else should be all lower-cased. For example:</p>\n\n<ul>\n<li><code>MyCompany.form.action.AutoLoad</code></li>\n</ul>\n</li>\n<li><p>Classes that are not distributed by Sencha should never use <code>Ext</code> as the top-level namespace.</p></li>\n<li><p>Acronyms should also follow CamelCased convention listed above. For example:</p>\n\n<ul>\n<li><code>Ext.data.JsonProxy</code> instead of <code>Ext.data.JSONProxy</code></li>\n<li><code>MyCompany.util.HtmlParser</code> instead of <code>MyCompary.parser.HTMLParser</code></li>\n<li><code>MyCompany.server.Http</code> instead of <code>MyCompany.server.HTTP</code></li>\n</ul>\n</li>\n</ul>\n\n\n<h3>2) Source Files</h3>\n\n<ul>\n<li>The names of the classes map directly to the file paths in which they are stored. As a result, there must only be one class per file. For example:\n\n<ul>\n<li><code>Ext.util.Observable</code> is stored in <code>path/to/src/Ext/util/Observable.js</code></li>\n<li><code>Ext.form.action.Submit</code> is stored in <code>path/to/src/Ext/form/action/Submit.js</code></li>\n<li><code>MyCompany.chart.axis.Numeric</code> is stored in <code>path/to/src/MyCompany/chart/axis/Numeric.js</code></li>\n</ul>\n\n\n<p>  whereby <code>path/to/src</code> is the directory of your application's classes. All classes should stay inside one directory and should be properly namespaced for the best development, maintenance and deployment experience.</p></li>\n</ul>\n\n\n<h3>3) Methods and Variables</h3>\n\n<ul>\n<li><p>Similarly to class names, method and variable names may only contain <strong>alphanumeric</strong> characters. Numbers are permitted but are discouraged in most cases, unless they belong to a technical term. Do not use underscores, hyphens, or any other nonalphanumeric character.</p></li>\n<li><p>Method and variable names should always be in camelCased. This also applies to acronyms.</p></li>\n<li><p>Examples</p>\n\n<ul>\n<li>Acceptable method names:\n\n<ul>\n<li><code>encodeUsingMd5()</code></li>\n<li><code>getHtml()</code> instead of <code>getHTML()</code></li>\n<li><code>getJsonResponse()</code> instead of <code>getJSONResponse()</code></li>\n<li><code>parseXmlContent()</code> instead of <code>parseXMLContent()</code></li>\n</ul>\n</li>\n<li>Acceptable variable names:\n\n<ul>\n<li><code>var isGoodName</code></li>\n<li><code>var base64Encoder</code></li>\n<li><code>var xmlReader</code></li>\n<li><code>var httpServer</code></li>\n</ul>\n</li>\n</ul>\n</li>\n</ul>\n\n\n<h3>4) Properties</h3>\n\n<ul>\n<li><p>Class property names follow the exact same convention with methods and variables mentioned above, except the case when they are static constants.</p></li>\n<li><p>Static class properties that are constants should be all upper-cased. For example:</p>\n\n<ul>\n<li><code>Ext.MessageBox.YES = \"Yes\"</code></li>\n<li><code>Ext.MessageBox.NO  = \"No\"</code></li>\n<li><code>MyCompany.alien.Math.PI = \"4.13\"</code></li>\n</ul>\n</li>\n</ul>\n\n\n<h2>III. Hands-on</h2>\n\n<hr />\n\n<h3>1. Declaration</h3>\n\n<h4>1.1) The Old Way</h4>\n\n<p>If you have ever used any previous version of <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS, you are certainly familiar with <code>Ext.extend</code> to create a class:</p>\n\n<pre><code>var MyWindow = Ext.extend(Object, { ... });\n</code></pre>\n\n<p>This approach is easy to followed to create a new class that inherit from another. Other than direct inheritance, however, we didn't have a fluent API for other aspects of class creation, such as configuration, statics and mixins. We will be reviewing these items in details shortly.</p>\n\n<p>Let's take a look at another example:</p>\n\n<pre><code>My.cool.Window = Ext.extend(Ext.Window, { ... });\n</code></pre>\n\n<p>In this example we want to <a href=\"http://en.wikipedia.org/wiki/Namespace_(computer_science)\">namespace</a> our new class, and make it extend from <code>Ext.Window</code>. There are two concerns we need to address:</p>\n\n<ol>\n<li><code>My.cool</code> needs to be an existing object before we can assign <code>Window</code> as its property</li>\n<li><code>Ext.Window</code> needs to exist / loaded on the page before it can be referenced</li>\n</ol>\n\n\n<p>The first item is usually solved with <code>Ext.namespace</code> (aliased by <code>Ext.ns</code>). This method recursively transverse through the object / property tree and create them if they don't exist yet. The  boring part is you need to remember adding them above <code>Ext.extend</code> all the time.</p>\n\n<pre><code>Ext.ns('My.cool');\nMy.cool.Window = Ext.extend(Ext.Window, { ... });\n</code></pre>\n\n<p>The second issue, however, is not easy to address because <code>Ext.Window</code> might depend on many other classes that it directly / indirectly inherits from, and in turn, these dependencies might depend on other classes to exist. For that reason, applications written before <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS 4 usually include the whole library in the form of <code>ext-all.js</code> even though they might only need a small portion of the framework.</p>\n\n<h3>1.2) The New Way</h3>\n\n<p>Ext JS 4 eliminates all those drawbacks with just one single method you need to remember for class creation: <code>Ext.define</code>. Basic syntax:</p>\n\n<pre><code>Ext.define({String} className, {Object} members, {Function} onClassCreated);\n</code></pre>\n\n<ul>\n<li><code>className</code>: The <a href=\"#\">class name</a></li>\n<li><code>members</code> is an object represents a collection of class members in key-value pairs</li>\n<li><code>onClassCreated</code> is an optional function callback to be invoked when all dependencies of this class are ready, and the class itself is fully created. Due to the <a href=\"#\">new asynchronous nature</a> of class creation, this callback can be useful in many situations. These will be discussed further in <a href=\"#\">Section IV</a></li>\n</ul>\n\n\n<p><strong>Example:</strong></p>\n\n<pre><code>Ext.define('My.sample.Person', {\n    name: 'Unknown',\n\n    constructor: function(name) {\n        if (name) {\n            this.name = name;\n        }\n\n        return this;\n    },\n\n    eat: function(foodType) {\n        alert(this.name + \" is eating: \" + foodType);\n\n        return this;\n    }\n});\n\nvar aaron = Ext.create('My.sample.Person');\n    aaron.eat(\"Salad\"); // alert(\"Aaron is eating: Salad\");\n</code></pre>\n\n<p>Note we created a new instance of <code>My.sample.Person</code> using the <code>Ext.create()</code> method.  We could have used the <code>new</code> keyword (<code>new My.sample.Person()</code>).  However it is recommended to get in the habit of always using <code>Ext.create</code> since it allows you to take advantage of dynamic loading.  For more info on dynamic loading see the <a href=\"#/guide/getting_started\">Getting Started guide</a></p>\n\n<h3>2. Configuration</h3>\n\n<h4>2.1) The Old Way</h4>\n\n<p>Previous to version 4, we didn't really have a way to distinguish between class properties and user-supplied configurations. Configurations were defined as normal class properties and documented using <code>@cfg</code> annotation. Let's take a look at a sample class. It's rather lengthy but it well describes the problems as a whole:</p>\n\n<pre><code>Ext.ns('My.own');\nMy.own.Window = Ext.extend(Object, {\n   /** @readonly */\n    isWindow: true,\n\n   /** @cfg {String} title The default window's title */\n    title: 'Title Here',\n\n   /** @cfg {Object} bottomBar The default config for the bottom bar */\n    bottomBar: {\n        enabled: true,\n        height: 50,\n        resizable: false\n    },\n\n    constructor: function(config) {\n        Ext.apply(this, config || {});\n\n        this.setTitle(this.title);\n        this.setBottomBar(this.bottomBar);\n\n        return this;\n    },\n\n    setTitle: function(title) {\n        // Change title only if it's a non-empty string\n        if (!Ext.isString(title) || title.length === 0) {\n            alert('Error: Title must be a valid non-empty string');\n        }\n        else {\n            this.title = title;\n        }\n\n        return this;\n    },\n\n    getTitle: function() {\n        return this.title;\n    },\n\n    setBottomBar: function(bottomBar) {\n        // Create a new instance of My.own.WindowBottomBar if it doesn't exist\n        // Change the config of the existing instance otherwise\n        if (bottomBar &amp;&amp; bottomBar.enabled) {\n            if (!this.bottomBar) {\n                this.bottomBar = Ext.create('My.own.WindowBottomBar', bottomBar);\n            }\n            else {\n                this.bottomBar.setConfig(bottomBar);\n            }\n        }\n\n        return this;\n    },\n\n    getBottomBar: function() {\n        return this.bottomBar;\n    }\n});\n</code></pre>\n\n<p>In short, <code>My.own.Window</code>:</p>\n\n<ul>\n<li>accepts a config object during instantiation, which is merged with the default properties of the class</li>\n<li>allows <code>title</code> and <code>bottomBar</code> to be changed during run-time via setters</li>\n</ul>\n\n\n<p>This approach has one advantage, yet it's the one drawback at the same time: you can overwrite any members of this class' instances during instantiation, including private methods and properties that should never be overwritten. The trade-off of encapsutation for flexibilty caused misusage in many applications in the past, which led to poor design as well as bad debugging and maintenance experience.</p>\n\n<p>Further more, there are other limitations:</p>\n\n<ul>\n<li><p><code>Ext.apply</code> doesn't merge object properties recursively. So in this example, you can't just override <code>bottomBar.height</code> to <code>60</code>, for instance, without supplying other default properties of <code>bottomBar</code> as well.</p></li>\n<li><p>Getters and setters have to be manually defined for each and every config property. It's not programmatically possible to clearly tell what properties are configurations, hence setters and getters can't be automatically generated.</p></li>\n</ul>\n\n\n<h4>2.2) The New Way</h4>\n\n<p>In <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS 4, we introduce a dedicated <code>config</code> property that gets processed by the powerful <a href=\"#\">Ext.Class pre-processors</a> before the class is created. Let's rewrite the above example:</p>\n\n<pre><code>Ext.define('My.own.Window', {\n   /** @readonly */\n    isWindow: true,\n\n    config: {\n        title: 'Title Here',\n\n        bottomBar: {\n            enabled: true,\n            height: 50,\n            resizable: false\n        }\n    },\n\n    constructor: function(config) {\n        this.initConfig(config);\n\n        return this;\n    },\n\n    applyTitle: function(title) {\n        if (!Ext.isString(title) || title.length === 0) {\n            alert('Error: Title must be a valid non-empty string');\n        }\n        else {\n            return title;\n        }\n    },\n\n    applyBottomBar: function(bottomBar) {\n        if (bottomBar &amp;&amp; bottomBar.enabled) {\n            if (!this.bottomBar) {\n                return Ext.create('My.own.WindowBottomBar', bottomBar);\n            }\n            else {\n                this.bottomBar.setConfig(bottomBar);\n            }\n        }\n    }\n});\n</code></pre>\n\n<p>And here's an example of how it can be used:</p>\n\n<pre><code>var myWindow = Ext.create('My.own.Window', {\n    title: 'Hello World',\n    bottomBar: {\n        height: 60\n    }\n});\n\nalert(myWindow.getTitle()); // alerts \"Hello World\"\n\nmyWindow.setTitle('Something New');\n\nalert(myWindow.getTitle()); // alerts \"Something New\"\n\nmyWindow.setTitle(null); // alerts \"Error: Title must be a valid non-empty string\"\n\nmyWindow.setBottomBar({ height: 100 }); // Bottom bar's height is changed to 100\n</code></pre>\n\n<p>With these changes:</p>\n\n<ul>\n<li><code>My.own.Window</code> class' code is significantly reduced, with even more functionalities</li>\n<li>Configurations are completely encapsulated from other class members</li>\n<li>Getter and setter, methods for every config property are automatically generated into the class' prototype during class creation, if the class does not have these methods already defined.</li>\n<li>An <code>apply</code> method is also generated for every config property.  The auto-generated setter method calls the <code>apply</code> method internally before setting the value.  Override the <code>apply</code> method for a config property if you need to run custom logic before setting the value. If <code>apply</code> does not return a value then the setter will not set the value.  For example see <code>applyTitle</code> above.</li>\n</ul>\n\n\n<h3>3. Statics</h3>\n\n<p>Static members can be defined using the <code>statics</code> config</p>\n\n<pre><code>Ext.define('Computer', {\n    statics: {\n        instanceCount: 0,\n        factory: function(brand) {\n            // 'this' in static methods refer to the class itself\n            return new this({brand: brand});\n        }\n    },\n\n    config: {\n        brand: null\n    },\n\n    constructor: function(config) {\n        this.initConfig(config);\n\n        // the 'self' property of an instance refers to its class\n        this.self.instanceCount ++;\n\n        return this;\n    }\n});\n\nvar dellComputer = Computer.factory('Dell');\nvar appleComputer = Computer.factory('Mac');\n\nalert(appleComputer.getBrand()); // using the auto-generated getter to get the value of a config property. Alerts \"Mac\"\n\nalert(Computer.instanceCount); // Alerts \"2\"\n</code></pre>\n\n<h3>4. Inheritance</h3>\n\n<p>Ext JS 4 supports inheritance through both subclassing and mixins. For more information on inheritance see the documentation for <a href=\"#/api/Ext.Class\">Ext.Class</a></p>\n\n<h3>6. Dependencies</h3>\n\n<p>Another new feature introduced in <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS 4 is dynamic loading of dependencies.  For more information see the documentation for <a href=\"#/api/Ext.Loader\">Ext.Loader</a></p>\n\n<h2>IV. Errors Handling &amp; Debugging</h2>\n\n<hr />\n\n<p>Ext JS 4 includes some useful features that will help you with debugging and error handling.</p>\n\n<ul>\n<li><p>You can use <code>Ext.getDisplayName()</code> to get the display name of any method.  This is especially useful for throwing errors that have the class name and method name in their description:</p>\n\n<pre><code>  throw new Error('['+ Ext.getDisplayName(arguments.callee) +'] Some message here');\n</code></pre></li>\n<li><p>When an error is thrown in any method of any class defined using <code>Ext.define()</code>, you should see the method and class names in the call stack if you are using a WebKit based browser (Chrome or Safari).  For example, here is what it would look like in Chrome:</p></li>\n</ul>\n\n\n<p><img src=\"guides/class_system/call-stack.png\" alt=\"Call Stack\" /></p>\n\n<h2>See Also</h2>\n\n<ul>\n<li><a href=\"http://www.sencha.com/blog/countdown-to-ext-js-4-dynamic-loading-and-new-class-system\">Dynamic Loading and the New Class System</a></li>\n<li><a href=\"http://edspencer.net/2011/01/classes-in-ext-js-4-under-the-hood.html\">Classes in <a href=\"#/api/Ext\" rel=\"Ext\" class=\"docClass\">Ext</a> JS 4: Under the Hood</a></li>\n<li><a href=\"http://edspencer.net/2011/01/ext-js-4-the-class-definition-pipeline.html\">The Class Defition Pipeline</a></li>\n</ul>\n\n"
});