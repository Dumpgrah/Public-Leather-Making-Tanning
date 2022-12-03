modded class MissionGameplay extends MissionBase
{
	override void OnMissionStart()
	{
		super.OnMissionStart();
		
		GetRPCManager().AddRPC( "Dumpgrah_LTWS", "RPCTanningLeatherWorkingSettings", this, SingeplayerExecutionType.Both );
		
        GetRPCManager().SendRPC("Dumpgrah_LTWS", "RPCTanningLeatherWorkingSettings", new Param1< TanningLeatherWorkingSettings >( NULL ), true, NULL);
	}
	
	void RPCTanningLeatherWorkingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< TanningLeatherWorkingSettings > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		m_TanningLeatherWorkingSettings = data.param1;
	}
};
modded class MissionServer extends MissionBase
{
	override void OnInit()
	{
		super.OnInit();
		GetTanningLeatherWorkingSettings();
		
		GetRPCManager().AddRPC( "Dumpgrah_LTWS", "RPCTanningLeatherWorkingSettings", this, SingeplayerExecutionType.Both );
	}
	
			
	void SendTanningLeatherWorkingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
        if (sender)
		{
			GetRPCManager().SendRPC("Dumpgrah_LTWS", "RPCTanningLeatherWorkingSettings", new Param1< TanningLeatherWorkingSettings >( GetTanningLeatherWorkingSettings() ), true, sender);
		}
	}
	
};