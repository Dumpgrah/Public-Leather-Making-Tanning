ref TanningLeatherWorkingSettings m_TanningLeatherWorkingSettings
class TanningLeatherWorkingSettings
{ 
	protected static string DirPATH = "$profile:Tanning&LeatherWorking";
	protected static string TanningLeatherWorkingPath = DirPATH + "\\Tanning&LeatherWorking.json";
	
	//Default Values
	string ConfigVersion = "1";
	
	int TimeToTanPeltPerLeather = 200;
	int GardenLimeUsedPerLeather = 210;
	int WildboarPeltToLeather = 6;
	int RabbitToLeather = 1;
	int CowPeltToLeather = 11;
	int PigPeltToLeather = 6;
	int DeerPeltToLeather = 8;
	int GoatPeltToLeather = 4;
	int BearPeltToLeather = 10;
	int SheepPeltToLeather = 4;
	int WolfPeltToLeather = 6;
	int MouflonPeltToLeather = 4;
	
	void TanningLeatherWorkingSettings()
	{
		
	}
	
	// Load config file or create default file if config doesn't exsit
	void Load(){
		if (FileExist(TanningLeatherWorkingPath)) //If config exist load File
		{
	        JsonFileLoader<TanningLeatherWorkingSettings>.JsonLoadFile(TanningLeatherWorkingPath, this);
			if ( ConfigVersion != "1")
			{
				ConfigVersion = "1";
				
				TimeToTanPeltPerLeather = 200;
				GardenLimeUsedPerLeather = 210;
				WildboarPeltToLeather =6;
				RabbitToLeather =1;
				CowPeltToLeather =11;
				PigPeltToLeather =6;
				DeerPeltToLeather =8;
				GoatPeltToLeather =4;
				BearPeltToLeather =10;
				SheepPeltToLeather =4;
				WolfPeltToLeather =6;
				JsonFileLoader<TanningLeatherWorkingSettings>.JsonSaveFile(TanningLeatherWorkingPath, this);
			}
		}

		else//File does not exist create file
		{
			if (!FileExist(DirPATH))
			{
				MakeDirectory(DirPATH);
			}
			JsonFileLoader<TanningLeatherWorkingSettings>.JsonSaveFile(TanningLeatherWorkingPath, this);
		}

	}
};

//Helper function to return Config
static ref TanningLeatherWorkingSettings GetTanningLeatherWorkingSettings()
{
	if (!m_TanningLeatherWorkingSettings)
	{
		m_TanningLeatherWorkingSettings = new TanningLeatherWorkingSettings;
		m_TanningLeatherWorkingSettings.Load();
	}
	return m_TanningLeatherWorkingSettings;
};