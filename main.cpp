#include<iostream>
#include<fstream>
using namespace std;

class Post;

class Facebook;

class Helper
{
public:
	Helper()
	{}
	~Helper()
	{
	}
	static int strlength(const char arr[])
	{
		int i = 0;
		for (; arr[i] != '\0'; i++)
		{

		}
		return i;
	}

	static void StringCopy(char*& dest, const char* src)
	{
		if (dest)
			delete dest;
		
		int i = 0;
		int l = strlength(src);
		dest = new char[l + 1];

		for (; i < l; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
	}

	static char* GetStringFromBuffer(const char* str)
	{
		if (str == 0)
			return 0;
		
		int l = strlength(str);

		char* ptr = 0;
		StringCopy(ptr, str);
		return ptr;
	}

	static int IsPresent(char* myStr, const char* strToFind)
	{
		int l1 = strlength(myStr); int l2 = strlength(strToFind);
		int j = 0;

		for (int i = 0; i < l1; i++)
		{
			if (myStr[i] == strToFind[j])
			{
				j++;
				if (j == l2)
					return i - l2 + 1;
			}
			else
			{
				j = 0;
			}
		}
		return -1;
	}

	static char* StringConcatenate(const char* ptr, const char* ptr1)
	{
		int l1 = strlength(ptr);
		int l2 = strlength(ptr1);
		int n = l1 + l2 + 2;       //Size of concatenated string
		int k = 0;

		char* temp = new char[n];

		for (int i = 0; i < l1; i++)
		{
			temp[k++] = ptr[i];
		}
		temp[k++] = ' ';       //Adds space after one string
		for (int i = 0; i < l2; i++)
		{
			temp[k++] = ptr1[i];
		}
		temp[k] = '\0';

		return temp;
	}

	static bool FindSubstring(char* info, char* str)
	{
		int a = IsPresent(info, str);


		if (a > -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static char* GiveNewID(const char c);

private:
};

class Date
{
private:
	int day;
	int month;
	int year;
	
public:

	
    static Date currentDate;
	static Date Yesterday;
	
	static void SetYesterday(int d, int m, int y)   //set day before current date
	{
		Yesterday.SetDate(d, m, y);
	}   
	
	static void SetCurrentDate(int d, int m, int y)     //Sets current date
	{
		cout << "Command:\tSet Current System Date ";
		currentDate.SetDate(d, m, y);
		currentDate.Print();
		SetYesterday(d - 1, m, y);
	}  

	Date(int a=0,int b=0,int c=0)
	{
		//cout << "\nDefault Constructor Called\n";
		day =a; month = b; year = c;
	}

	void Print()
	{
		cout << day << "/" << month << "/" << year;
	}

	void SetDate(int d, int m, int y)
	{
		day = d; month = m; year = y;
	}

	~Date()
	{
		//cout << "\nDestructor Called\n";
	}

	void Input()
	{
		while (1)
		{
			cout << "Enter day: "; cin >> day;
			if (day > 0 && day <= 31)
			{
				break;
			}
		}
		while (1)
		{
			cout << "Enter month: "; cin >> month;
			if (month > 0 && month <= 12)
			{
				break;
			}
		}
		while (1)
		{
			cout << "Enter year: "; cin >> year;
			if (year > 0)
			{
				break;
			}
		}
	}

	void ReadDate(ifstream& fin)
	{
		fin >> day; fin >> month; fin >> year;
	}

	void SetDay(int d)
	{
		day = d;
	}

	void SetMonth(int m)
	{
		month = m;
	}

	void SetYear(int y)
	{
		year = y;
	}

	int GetDay()
	{
		return day;
	}

	int GetMonth()
	{
		return month;
	}

	int GetYear()
	{
		return year;
	}

	int compare(Date c1)
	{
		if (year > c1.year)
		{
			return 1;
		}
		else if (year < c1.year)
		{
			return -1;
		}
		else
		{
			if (month > c1.month)
			{
				return 1;
			}
			else if (month < c1.month)
			{
				return -1;
			}
			else
			{
				if (day > c1.day)
				{
					return 1;
				}
				else if (day < c1.day)
				{
					return -1;
				}
				else
				{
					return 0;
				}
			}
		}
	}

	Date IncrementMonth()
	{
		Date temp;
		temp.day = day;
		temp.month = month;
		temp.year = year;
		if ((month + 1) > 12)
		{
			temp.year++;
		}
		temp.month = (month + 1) % 12;
		return temp;
	}

	Date operator=(const Date& rhs)
	{
		day = rhs.day;
		month = rhs.month;
		year = rhs.year;
		/*Date result(rhs.day-1, rhs.month, rhs.year);*/
		return *this;
	}

};

 Date Date::currentDate;
 Date  Date::Yesterday;

class Activity
{
public:
	Activity(int t = 0, char* v = 0)     //Overloaded Default constructor
	{
		type = t;
		value = v;
	}  

	void SetActivity(int t, char* v)    //initializes activity
	{
		type = t;
		value = Helper::GetStringFromBuffer(v);
	}

	void Print()
	{
		if(type==1)
		{
			cout << " is Feeling " << value;
		}
		else if (type == 2)
		{
			cout << " is Thinking about " << value;
		}
		else if (type == 3)
		{
			cout << " is Making " << value;
		}
		else if (type == 4)
		{
			cout << " is Celebrating " << value;
		}
	}
	
	~Activity()
	{
		if (value)
			delete value;
	}

private:
	int type;
	char* value;
};

class Object
{
public:
	Object()
	{
		ID =0;
	}
	
	virtual ~Object()
	{
		if (ID)
			delete[] ID;
	}

	virtual void PrintName() = 0;

	void SetID(char* id)
	{
		if (ID) 
		{
			delete[] ID;
		}
		ID = Helper::GetStringFromBuffer(id);
	}

	char* GetID()
	{
		return ID;
	}

	virtual void PrintListView() = 0;    //pure virtual

	virtual void AddPost(Post* p) = 0;       //Adds new post to user or page  ,  Pure virtual

private:
	char* ID;
};

class Page:public Object  //Polymorphism
{
public:
	Page()
	{
		title = 0; k = 0;

		Timeline = new Post* [10];
		for (int i = 0; i < 10; i++)
		{
			Timeline[i] = 0;
		}
	}

	~Page()
	{
		if (title)
			delete[] title;

		if (Timeline)
		{
			for (int i = 0; i < 10; i++)
			{
				if (Timeline[i])
					delete Timeline[i];
			}

			delete[] Timeline;
		}
	}

	void PrintListView()
	{
		cout << GetID() << "-" << title;
	}

	void ReadData(ifstream& fin)
	{
		char temp[100];
		fin >> temp;
		SetID(temp);

		fin.ignore();
		fin.getline(temp, 100);
		SetTitle(temp);
	}

	void SetTitle(char* t)
	{
		title=Helper::GetStringFromBuffer(t);
	}

	void AddPost(Post* p)
	{
		if (k <10)
			Timeline[k++] = p;
		else
			cout << "no vacancies\n";
	}

	void ViewPage();
	
	void ViewTimeline(bool flag=1);

	void PrintName()
	{
		cout << title;
	}

	char* GetTitle()
	{
		return title;
	}

private:
	char* title;
	Post** Timeline;
	int k;
};

class User:public Object //Polymorphism
{
public:
	User()
	{
		Fname = 0; k = 0;
		Lname = 0;
		LikedPages = new Page* [10];

		for (int i = 0; i < 10; i++)
		{
			LikedPages[i] = 0;
		}

		FriendList = new User * [10];

		for (int i = 0; i < 10; i++)
		{
			FriendList[i] = 0;
		}

		Timeline = new Post * [10];
		for (int i = 0; i < 10; i++)
		{
			Timeline[i] = 0;
		}

		for (int i = 0; i < 10; i++)
		{
			arr[i] = -1;
		}
		
	}
	
	void ReadData(ifstream& fin)
	{
		char temp[30];
		fin >> temp;
		SetID(Helper::GetStringFromBuffer(temp));

		fin >> temp;
		Fname = Helper::GetStringFromBuffer(temp);

		fin >> temp;
		Lname = Helper::GetStringFromBuffer(temp);

	}

	char* GetFname()
	{
		return Fname;
	}

	char* GetLname()
	{
		return Lname;
	}

	void PrintName()
	{
		cout << Fname << " " << Lname;
	}

	void LikePage(Page* p)     //This likes a new page
	{
		int count = 0;
		for (int i = 0; i < 10; i++)
		{
			if (LikedPages[i] == 0)
			{
				count++;
			}
		}

		if (count == 0)
		{
			cout << "No Space\n";
		}
		else
		{
			bool flag = false;
			for (int i = 0; i < 10; i++)
			{
				if (LikedPages[i] == p)
				{
					cout << "Page is already liked\n";
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				for (int i = 0; i < 10; i++)
				{
					if (LikedPages[i] == 0)
					{
						LikedPages[i] = p;
						//cout << "Page has been liked\n";
						break;
					}
				}
			}
		}
	}

	void AddFriend(User* u)     //adds friends to user
	{
		int count = 0;
		for (int i = 0; i < 19; i++)
		{
			if (FriendList[i] != 0)
			{
				count++;
			}
		}

		if (count == 19)
		{
			cout << "There are no vacancies\n";
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (FriendList[i] == u)
				{
					cout << "User is already a friend\n";
					break;
				}
			}

			for (int i = 0; i < 19; i++)
			{
				if (FriendList[i] == 0)
				{
					FriendList[i] = u;
					//cout << "User have been added as Friend\n";
					break;
				}
			}
		}
	}

	void PrintListView()
	{
		cout<< GetID() << " - " << Fname << " " << Lname;
	}
	
	void ViewFriendList()
	{
		cout << "Command:\tView Friend List\n";
		cout << "******************************************************************\n";
		cout << Fname<<" "<<Lname<<" - Friend List:\n\n";

		for (int i = 0; i < 10; i++)
		{
			if (FriendList[i] != 0)
			{
				FriendList[i]->PrintListView();
				cout << endl;
			}
		}
		cout << "******************************************************************\n";
	}

	void ViewLikedPages()
	{
		cout << "Command:\tView Liked Pages\n";
		cout << "******************************************************************\n";
		cout << Fname << " " << Lname << " - Liked Pages:\n\n";
		
		for (int i = 0; i < 10; i++)
		{
			if (LikedPages[i] != 0)
			{
				LikedPages[i]->PrintListView();
				cout << endl;
			}
		}
		cout << "******************************************************************\n";
	}

	void SetFname(char* n)
	{
		Helper::StringCopy(Fname, n);
	}

	void SetLname(char* n)
	{
		Helper::StringCopy(Lname, n);
	}

	void AddPost(Post* p)
	{
		if (k <10)
			Timeline[k++] = p;
		else
			cout << "no vacancies\n";
	}

	void ViewTimeline(bool flag=1);
	 
	void PrintPostsSharedByFriends()
	{
		for (int i = 0; FriendList[i] != 0; i++)
		{
			FriendList[i]->ViewTimeline(false);
		}
	}

	void PrintPostsSharedByPages()
	{
		for (int i = 0; LikedPages[i] != 0; i++)
		{
			LikedPages[i]->ViewTimeline(false);
		}
	}

	void ViewHome()   //prints posts of last 24 hrs
	{
		cout << "Command:\tView Home of " << Fname << " " << Lname << endl;
		cout << "*********************************************************************\n";
		PrintPostsSharedByFriends();
		cout << endl;
		PrintPostsSharedByPages();
		cout << endl;
		cout << "*********************************************************************\n";
	}

	~User()
	{
		if (Fname)
			delete[] Fname;
		if (Lname)
			delete[] Lname;
		if (LikedPages)
			delete[] LikedPages;
		if (FriendList)
			delete[] FriendList;

		if (Timeline)
		{
			for (int i = 0; i<10; i++)
			{
				if (Timeline[i]!=NULL)
					delete Timeline[i];
			}

			delete[] Timeline;
		}
	}

	void ShareMemory(Post* p, const char* t);    //creates a memory

	void PostComment(Post* p, const char* t);     //adds new comment

	void SeeMemories();

private:
	char* Fname;
	char* Lname;
	Page** LikedPages;
	User** FriendList;
	Post** Timeline;
	int k;
	int arr[10];
	int s;
};

class Comment
{
public:
	Comment(const char c=0, const char* t = 0, Object * poster = 0)  //overloaded default constructor
	{
		ID = Helper::GiveNewID(c);
		text = Helper::GetStringFromBuffer(t);
		OnPost = 0;
		PostedBy = poster;
	}
	
	~Comment()
	{
		if (ID)
			delete[] ID;
		if (text)
			delete[] text;
	}

	void SetComment(char* id, char* t, Post* p, Object* poster)    //gives values to comments
	{
		if (ID) delete[] ID;
		ID = Helper::GetStringFromBuffer(id);
		if (text) delete[] text;
		text = Helper::GetStringFromBuffer(t);
		OnPost = p;
		PostedBy = poster;
	}

	void Print()
	{
		cout << "\n\t\t";
		PostedBy->PrintName();
		cout << " wrote : ";
		cout <<"\""<< text<<"\"";
	}

	char* GetID()
	{
		return ID;
	}

	static int TotalComments;

private:
	char* text;
	Post* OnPost;
	char* ID;
	Object* PostedBy;

};

int Comment::TotalComments=0;

class Post
{
public:
	static int TotalPosts;

	Post(const char c=0,const char* ch = 0)    //overloaded default constructor
	{
		ID = Helper::GiveNewID(c);
		k = 0;
		j = 0;
		text = Helper::GetStringFromBuffer(ch);
		likes = 0;
		SharedBy = 0; comments = 0;
		activity = 0;

		LikedBy = new Object * [10];

		for (int i = 0; i < 10; i++)
		{
			LikedBy[i] = 0;
		}
		
		comments = new Comment*[10];

		for (int i = 0; i < 10; i++)
		{
			comments[i] = 0;
		}
	}
	
	void ReadData(ifstream& fin)
	{
		char temp[100]; char temp1[100];
		int type;
		fin >> type;
		fin >> temp;
		
		SharedDate.ReadDate(fin);
		fin.ignore();
		fin.getline(temp1, 99);
		setPost(temp, temp1);

		if (type == 2)
		{
			fin >> type;
			fin.ignore();
			fin.getline(temp, 100);
			setPostActivity(type, temp);
		}
	}

	virtual void PrintListView(bool flag=0,bool flag1=1)
	{
		if (activity)
		{
			cout << endl;
			cout << "---";
			SharedBy->PrintName();
			activity->Print();
			
			cout << "\n   \"" << text << "\"";

			if (flag)
			{
				cout << "...("; SharedDate.Print(); cout << ")" << endl;
			}
		}
		else
		{
			cout << "---";
			SharedBy->PrintName();
			cout << " shared ";
			cout << "\"" << text << "\"";
			if (flag)
			{
				cout << "...("; SharedDate.Print(); cout << ")" << endl;
			}
		}
		
		if(flag1)
		{
			if (comments[0])
			{
				for (int i = 0; comments[i] != 0; i++)
				{
					comments[i]->Print();
				}
			}
		}
		cout << endl << endl << endl;
	}

	void PrintText()
	{
		cout << text;
	}

	void LikePost(User* u)     //likes a post
	{
		LikedBy[k++] = u;
	}

	void setPost(char* id, char* t)     //gives values to post
	{
		ID = Helper::GetStringFromBuffer(id);
		text = Helper::GetStringFromBuffer(t);
	}

	void setPostActivity(int t, char* v)   //gives value to activity
	{
		activity = new Activity;
		activity->SetActivity(t, v);
	}

	void SetSharedBy(Object* o)
	{
		SharedBy = o;
	}

	void SetLikedBy(Object* o)
	{
		LikedBy[k++] = o;
	}

	char* GetID()
	{
		return ID;
	}

	void AddComment(Comment* c)
	{
		if (j < 10)
			comments[j++] = c;
		else
			cout << "no vacancies\n";
	}

	void PostComment(const char* comment, User* u)
	{
		if (j < 10)
			comments[j++] = new Comment('c', comment, u);  //Initializing new comment
		else
			cout << "comment capacity reached\n";
			
	}

	void PrintLikedBy()
	{
		cout << "Command:\t" << ID <<" is liked by:"<< endl;
		cout << "**********************************************************\n";
		for (int i = 0; LikedBy[i] != 0; i++)
		{
			LikedBy[i]->PrintListView();
			cout << endl;
		}
		cout << "******************************************************************\n";
	}

	Date GetDate()
	{
		return SharedDate;
	}

	void PrintSharedByName()
	{
		SharedBy->PrintName();
	}

	~Post() 
	{
		if (ID)
			delete[] ID;
		if (text)
			delete[] text;

		for (int i=0;i<10;i++)
		{
			if (comments[i])
				delete comments[i];
		}
		delete[] comments;
		
		if (LikedBy)
			delete[] LikedBy;
		if (activity)
			delete activity;
	}

private:
	char* ID;
	char* text;
	int likes;
	Date SharedDate;
	Object** LikedBy;
	Object* SharedBy;
	Comment** comments;
	Activity* activity;
	int k;
	int j;
};

int Post::TotalPosts = 0;

class Memory:public Post  //Polymorphism
{
public:
	Memory(Post* p=0, const char* t=0):Post('p', t)     //member initiazer list
	{
		OriginalPost = p;
	}
	
	~Memory()
	{
	}

	void PrintListView(bool flag=1,bool flag1=1)
	{
		if(flag1)
		{
			cout << "~~~"; OriginalPost->PrintSharedByName();  cout << " shared a memory~~~...(";
			Date::currentDate.Print();
			cout << ")\n";
			cout << "\"";
		}
		
		PrintText();
		 
		if (flag1) cout << "\"";
		
		if(!flag1)
	    {
			 cout << "\n\nOn this Day\n";
			 Date f = OriginalPost->GetDate();
			 cout << Date::currentDate.GetYear() - f.GetYear() << " years ago\n";
		}
		 else
		 {
			 Date f = OriginalPost->GetDate();
			 cout << "\n\t" << "(" << Date::currentDate.GetYear() - f.GetYear() << " years ago)\n";
		 }
		
		OriginalPost->PrintListView(true,!flag1);
	}

private:
	Post* OriginalPost;
};

class Facebook
{
public:
	
	static int TotalPages;
	static int TotalUsers;
	
	
	Facebook()
	{
		pages = 0;
		users = 0;
		posts = 0;
	}

	Page* SearchPageByID(const char* p)
	{
		if (p == 0)
		{
			return 0;
		}
		
		for (int i = 0; i < 12; i++)
		{
			int a = Helper::IsPresent(pages[i]->GetID(), p);
			if (a != -1)
			{
				return pages[i];
			}
		}
		return 0;
	}

	User* SearchUserByID(const char* u)
	{
		if (u == 0)
		{
			return 0;
		}
		for (int i = 0; i < 20; i++)
		{
			int a = Helper::IsPresent(users[i]->GetID(), u);
			if (a != -1)
			{
				return users[i];
			}
		}
		return 0;
	}

	Post* SearchPostByID(const char* p)
	{
		if (p == 0)
		{
			return 0;
		}
		for (int i = 0; i < 20; i++)
		{
			int a = Helper::IsPresent(posts[i]->GetID(), p);
			if (a != -1)
			{
				return posts[i];
			}
		}
		return 0;
	}

	Object* SearchObjectByID(const char* n)
	{
		User* u = SearchUserByID(n);
		Page* p = SearchPageByID(n);

		if (u != 0)
		{
			return u;
		}
		else if (p != 0)
		{
			return p;
		}
		else
		{
			return 0;
		}
	}

	void LoadPagesFromFile()
	{
		ifstream fin("PageData.txt");
		if(fin)
		{
			char temp[50];
			fin >> TotalPages;
			pages = new Page * [TotalPages];

			for (int i = 0; i < TotalPages; i++)
			{
				pages[i] = new Page();
				pages[i]->ReadData(fin);
			}
			fin.close();
		}
		else
		{
			cout << "File not opened or corrupt\n";
		}
	}

	void LoadUsersFromFile()
	{
		ifstream fin("UserData.txt");
		if (fin)
		{
			fin >> TotalUsers;
			char*** ptr = new char** [TotalUsers];

			for (int i = 0; i < TotalUsers; i++)
			{
				ptr[i] = new char* [10];
			}

			for (int i = 0; i < TotalUsers; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					ptr[i][j] = 0;
				}
			}

			users = new User * [TotalUsers];
			char temp[30];

			for (int i = 0; i < TotalUsers; i++)
			{
				users[i] = new User;
				users[i]->ReadData(fin);
				
				int j = 0;
				temp[0] = ' ';
				while (1)
				{
					fin >> temp;
					if (temp[0] == '-')
					{
						break;
					}
					ptr[i][j++] = Helper::GetStringFromBuffer(temp);
				}

				temp[0] = ' ';
				while (1)
				{
					fin >> temp;
					if (temp[0] == '-')
					{
						break;
					}
					Page* like = SearchPageByID(temp);
					if (like)
					{
						users[i]->LikePage(like);
					}
				}
			}
			fin.close();

			for (int i = 0; i < TotalUsers; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					User* userfriend = SearchUserByID(ptr[i][j]);
					if (userfriend)
						users[i]->AddFriend(userfriend);
				}
			}

			for (int i = 0; i < TotalUsers; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (ptr[i][j])
						delete[] ptr[i][j];
				}
				delete[] ptr[i];
			}
			delete[] ptr;
		}
		else
		{
			cout << "File not opened or corrupt\n";
		}

	}

	void LoadPostsFromFile()
	{
		ifstream fin("PostData.txt");
		if(fin)
		{
			char temp[100];
			fin >> Post::TotalPosts;
			posts = new Post * [Post::TotalPosts];

			for (int i = 0; i < Post::TotalPosts; i++)
			{
				posts[i] = new Post;
				posts[i]->ReadData(fin);


				fin >> temp;
				Object* o = SearchObjectByID(temp);
				o->AddPost(posts[i]);

				posts[i]->SetSharedBy(o);

				while (1)
				{
					fin >> temp;
					if (temp[0] == '-')
					{
						break;
					}

					o = SearchObjectByID(temp);
					posts[i]->SetLikedBy(o);
				}
			}
			fin.close();
		}
		else
		{
			cout << "File not opened or corrupt\n";
		}
	}

	void LoadCommentsFromFile()
	{
		ifstream fin("CommentData.txt");
		if(fin)
		{
			fin >> Comment::TotalComments;
			char id[100]; char text[100]; char OnPost[100]; char PostedBy[100];


			for (int i = 0; i < Comment::TotalComments; i++)
			{
				Comment* temp = new Comment;
				fin >> id;

				fin >> OnPost;
				Post* p = SearchPostByID(OnPost);
				p->AddComment(temp);

				fin >> PostedBy;
				Object* poster = SearchObjectByID(PostedBy);

				fin.ignore();
				fin.getline(text, 100);
				temp->SetComment(id, text, p, poster);
			}
			fin.close();
		}
		else
		{
			cout << "File not opened or corrupt\n";
		}
	}

	void LikePost(const char* n, User* u)
	{
		cout << "Command:\tLikePost(" << n << ")"<<endl;
		Post* p = SearchPostByID(n);
		p->LikePost(u);
		cout << "**************************************************\n";
	}

	void Load()
	{
		LoadPagesFromFile();
		LoadUsersFromFile();
		LoadPostsFromFile();
		LoadCommentsFromFile();
	}

	~Facebook() 
	{
		if (pages)
		{
			for (int i = 0; i < TotalPages; i++)
			{
				if (pages[i])
					delete pages[i];
			}
			delete[] pages;
		}

		
		for (int i = 0; i < TotalUsers; i++)
		{
			if (users[i])
				delete users[i];
		}
		
		delete[] users;


		if (posts)
			delete[] posts;
	}

	void ViewPage(const char* n)
	{
		Page* p = SearchPageByID(n);

		
		cout << "Command:\tViewPage(" << n <<")"<< endl;
		cout << "*********************************************************************\n";
		
		p->ViewTimeline();

		//cout << "***************************************************************\n";
	}

	void Run(const char* check)
	{
		User* testUser = SearchUserByID(check);
		if (!testUser)
		{
			cout << "User not Found\n";
			return;
		}
		
		Date::SetCurrentDate(15, 11, 2017);
		cout << "\nSystem Date:\t"; Date::currentDate.Print();
		cout << "\n\nCommand:\tSet Current User " << check << endl;

		
		cout << testUser->GetFname() << " " << testUser->GetLname() << " successfully set as Current User\n";
		cout << "*****************************************************************\n";

		testUser->ViewFriendList();
	
		testUser->ViewLikedPages();
		
		testUser->ViewHome();

		testUser->ViewTimeline();

		
		Post* p = SearchPostByID("post5");
		p->PrintLikedBy();
		LikePost("post5", testUser);
		p->PrintLikedBy();
		
		
		p = SearchPostByID("post4");
		testUser->PostComment(p, "Good Luck for your result");
		ViewPost("post4");

		
		p = SearchPostByID("post8");
		testUser->PostComment(p, "Thanks for the wishes");
		ViewPost("post8");

		
		p = SearchPostByID("post10");
		testUser->ShareMemory(p, "Never thought I will be specialist in this field");

		testUser->SeeMemories();

		testUser->ViewTimeline();

		ViewPage("p1");
	}

	void ViewPost(const char* name)
	{
		Post* p = SearchPostByID(name);
		p->PrintListView(true);
		cout << "**************************************************************\n";
	}

private: 
	Page** pages=0;
	User** users;
	Post** posts;
};

int Facebook::TotalPages = 0;
int Facebook::TotalUsers = 0;


void User:: ViewTimeline(bool flag)
{
	if (flag)
	{
		cout << Fname << " " << Lname << " TimeLine:\n";
		cout << "***************************************************************\n";
		for (int i = 0; Timeline[i] != 0; i++)
		{
			Timeline[i]->PrintListView(true);
			cout << endl;
		}
		cout << "***************************************************************\n";
	}
	else
	{
		for (int i = 0; Timeline[i] != 0; i++)
		{
			Date f = Timeline[i]->GetDate();


			if (f.compare(Date::Yesterday) == 0 || f.compare(Date::currentDate) == 0)
			{
				Timeline[i]->PrintListView();
			}
		}
	}
}

void Page::ViewPage()
{
		PrintListView();
		for (int i = 0; Timeline[i] != 0; i++)
		{
			Timeline[i]->PrintListView(true);
		}
}

void Page::ViewTimeline(bool flag)
{
	if(flag)
	{
		for (int i = 0; Timeline[i]!=0; i++)
		{
			Timeline[i]->PrintListView(true);
		}
	}
	else
	{
		for (int i = 0; Timeline[i]!=0; i++)
		{
			Date f = Timeline[i]->GetDate();

			if (f.compare(Date::Yesterday) == 0 || f.compare(Date::currentDate) == 0)
			{
				Timeline[i]->PrintListView(false);
			}
		}
	}
}

void User::ShareMemory(Post* p, const char* t)
{
	cout << "Command:\tShareMemory(" << p->GetID() << ", \"" << t << "\")\n";
	
	Date f = p->GetDate();
	if (f.GetDay() == Date::currentDate.GetDay() && f.GetMonth() == Date::currentDate.GetMonth())
	{
		Timeline[k] = new Memory(p, t);
		arr[s++] = k;
		k++;
		Post::TotalPosts++;
	}
	cout << "************************************************************\n";
}

void User::SeeMemories()
{
	cout << "Command:\tSeeMemory()\n";
	cout << "**********************************************************\n";
	
	for (int i = 0; arr[i] != -1; i++)
	{
		Timeline[arr[i]]->PrintListView(true,false);
	}
	cout << "**********************************************************\n";
}

void User::PostComment(Post* p, const char* t)
{
	cout << "Command:\tPostComment(" << p->GetID() << ",\"" << t << "\")\n";
	cout << "**************************************************************\n";
	p->PostComment(t, this);
	Comment::TotalComments++;
}

char* Helper::GiveNewID(const char c)
{
	if (c == 'c')
	{
		char* ID = new char[4];
		ID[0] = 'c';

		int a = Comment::TotalComments / 10;
		ID[1] = a + '0';

		int b = Comment::TotalComments % 10;
		ID[2] = b + 1+'0';
		ID[3] = '\0';
		return ID;
	}
	else if (c == 'p')
	{
		char* ID = 0;
		char temp[3];
		temp[0] = (Post::TotalPosts / 10) + '0';
		temp[1] = (Post::TotalPosts % 10) +1+ '0';
		temp[2] = '\0';
		ID = StringConcatenate("post", temp);
		cout << ID;
		return ID;
	}
	else
	{
		return 0;
	}
}

void main()
{
	Facebook fb;
	fb.Load();
	fb.Run("u7");
}
