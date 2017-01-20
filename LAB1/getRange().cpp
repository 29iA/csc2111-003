int* getRange()
{
	string prompt;
	string storage;
	
	cout << "Enter the file name containing the range for the secret number: ";
	storage = KEYBOARD.readString(prompt);
	
	ReadFile.createReadFile(storage);
	
	int *range = new int[2];
	
	for(int i = 0; i < 2; i++) {
		string *temp;
		
		temp = rf->ReadFile.readLine(rf);
		range[i] = Text.a_to_i(temp);
	}
	return range;
}

{
  string rangeFilename;


  cout << "\n\nEnter the file name containing the range for the secret number:  ";
  cin >> rangeFilename;
  ifstream rangeFile;
  rangeFile.open(rangeFilename.c_str());
  int *range = new int[2];

  for (int i =0; i < 2; i++)
  {
    rangeFile >> range[i];
  }

  rangeFile.close();

  return range;
}