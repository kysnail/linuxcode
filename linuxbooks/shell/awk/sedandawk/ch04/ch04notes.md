## Chapter 4 - Writting sed Scripts

### Applying Commands in a Script

**src/01**

	==$ tree
	.
	├── out
	├── replace-sed
	└── sampletext.tx

**replace-sed**

	$ cat replace-sed 
	s/pig/cow/g
	s/cow/horse/g

**sampletext.txt

	$ cat sampletext.txt 
	Ungualtes: horse - pig - cow

	The most important agricultural domesticated animals are ungulates. They will be discussed on this page. Normally, the ungulates are divided into even-toed and odd-toed ungulates. The even-toed ungulates are subsequently divided into ruminants and the swine family. So there are three groups. Most ungulates are quite large animals, that have specialized their digestive tract and limbs in different ways. We will focus on this.

	On this page we focus on three farm animals:

	 * The horse as representative of the odd-toed ungulates.
	 * The pig as representative of the swine family.
	 * The cow as representative of the ruminants.

**out**

	$ cat out 
	Ungualtes: horse - horse - horse

	The most important agricultural domesticated animals are ungulates. They will be discussed on this page. Normally, the ungulates are divided into even-toed and odd-toed ungulates. The even-toed ungulates are subsequently divided into ruminants and the swine family. So there are three groups. Most ungulates are quite large animals, that have specialized their digestive tract and limbs in different ways. We will focus on this.

	On this page we focus on three farm animals:

	 * The horse as representative of the odd-toed ungulates.
	 * The horse as representative of the swine family.
	 * The horse as representative of the ruminants.

**Execute following:**

	$ sed -f replace-sed sampletext.txt > out

#### The Pattern Space

