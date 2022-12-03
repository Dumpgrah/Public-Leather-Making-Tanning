class CfgPatches
{
	class LeatherCrafting
	{
		units[] = {""};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Cooking"};
	};
};
class CfgMods
{
	class LeatherCrafting
	{
		dir = "LeatherCrafting";
		name = "LeatherCrafting";
		credits = "Dumpgrah";
		author = "Dumpgrah";
		authorID = "0";
		version = "1.25";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"LeatherCrafting\Scripts\3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"LeatherCrafting\scripts\4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"LeatherCrafting\Scripts\5_Mission"};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxygarden_lime: ProxyAttachment
	{
		scope = 2;
		InventorySlot = "Lime";
		model = "DZ\gear\consumables\garden_lime";
	};
	class ProxyLCT101Dummy_Proxy: ProxyAttachment
	{
		scope = 2;
		InventorySlot = "SawnOffWeapons";
		model = "LeatherCrafting\Assets\Custom Work\Makeshift Sewn Holster\LCT101Dummy Proxy";
	};
};
class CfgSlots
{
	class Slot_DryRackLeather
	{
		name = "DryRackLeather";
		displayName = "DryRackLeather";
		ghostIcon = "animal_pelt";
	};
	class Slot_SawnOffWeapons
	{
		name = "SawnOffWeapons";
		displayName = "Sawn Off Weapons";
		ghostIcon = "animal_pelt";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Clothing;	
	class PlateCarrierHolster;
	class ChestHolster;
	class FramehookandRope: Inventory_Base
	{
		scope = 2;
		displayName = "Hooks and Rope";
		descriptionShort = "Bone hooks and Rope, might be used for stretching something out";
		model = "LeatherCrafting\Assets\DryingRack\BoneHook&Rope.p3d";
		itemSize[] = {1,3};
		weight = 284;
	};
	class UnfinishedDryingFrame: Inventory_Base
	{
		scope = 2;
		displayName = "Unfinished Frame";
		descriptionShort = "Drying Rack just missing hooks to stretch the pelt for drying";
		model = "LeatherCrafting\Assets\DryingRack\UnfinishedDryingRack.p3d";
		itemSize[] = {8,8};
		weight = 1084;
	};
	class DryingFrame: Inventory_Base
	{
		scope = 2;
		displayName = "Drying Frame";
		descriptionShort = "Drying Rack with hooks for Drying Leather";
		model = "LeatherCrafting\Assets\DryingRack\DryingRack.p3d";
		animClass = "Knife";
		isMeleeWeapon = 1;
		rotationFlags = 0;
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
		weight = 1366;
		itemSize[] = {10,10};
		fragility = 0.005;
		repairableWithKits[] = {0};
		simpleHiddenSelections[] = {"Leather","CuredLeather"};
		attachments[] = {"DryRackLeather","Lime"};
		class GUIInventoryAttachmentsProps
		{
			class PeltDryingArea
			{
				name = "Pelt";
				description = "";
				attachmentSlots[] = {"DryRackLeather"};
				icon = "animal_pelt";
			};
			class PeltDryingLime
			{
				name = "Lime";
				description = "";
				attachmentSlots[] = {"Lime"};
				icon = "lime";
			};
		};
	};
	class LeatherSewedHolster : PlateCarrierHolster
	{
		scope=2;
		displayName="Leather Holster";
		descriptionShort="Hand Made Leather Holster, Hand Stitched and decent Quality";
		model="LeatherCrafting\Assets\Custom Work\Makeshift Holster\MakeShiftHolster.p3d";
		weight=110;
		itemSize[]={2,3};
		varWetMax=0.79000002;
		heatIsolation=0;
		repairableWithKits[]={3};
		repairCosts[]={25};
	};
	class LeatherSawnedOffHolster : PlateCarrierHolster
	{
		scope=2;
		displayName="Sawned Leather Holster";
		descriptionShort="Hand Made Leather Holster, Hand Stitched and decent Quality";
		model="LeatherCrafting\Assets\Custom Work\Makeshift Sewn Holster\SewnoffGunHolster.p3d";
		inventorySlot[]=
		{
			"Belt_Right"
		};
		attachments[]=
		{
			"SawnOffWeapons"
		};
		weight=110;
		itemSize[]={2,3};
		varWetMax=0.79000002;
		heatIsolation=0;
		repairableWithKits[]={3};
		repairCosts[]={25};
	};

	class HandMadeChestHolster: ChestHolster
	{
		scope=2;
		displayName="Hand Made Leather Holster";
		descriptionShort="Leather Holster made from freshly tanned leather";
		model="\DZ\characters\vests\chest_holster_g.p3d";
		simulation="clothing";
		vehicleClass="Clothing";
		weight=310;
		itemSize[]={3,2};
		varWetMax=0.249;
		heatIsolation=0;
		repairableWithKits[]={3};
		repairCosts[]={25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\vests\chest_holster_m.p3d";
			female="\DZ\characters\vests\chest_holster_f.p3d";
		};
		hiddenSelectionsTextures[]=
		{
			"LeatherCrafting\Assets\Custom Work\Makeshift Chest Holster\Data\Leather Chest Holster_co.paa",
			"LeatherCrafting\Assets\Custom Work\Makeshift Chest Holster\Data\Leather Chest Holster_co.paa",
			"LeatherCrafting\Assets\Custom Work\Makeshift Chest Holster\Data\Leather Chest Holster_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"LeatherCrafting\Assets\Custom Work\Makeshift Chest Holster\Data\Leather Chest Holster.rvmat",
			"LeatherCrafting\Assets\Custom Work\Makeshift Chest Holster\Data\Leather Chest Holster.rvmat",
			"LeatherCrafting\Assets\Custom Work\Makeshift Chest Holster\Data\Leather Chest Holster.rvmat"
		};

	};
	class LeatherShoes_ColorBase: Clothing
	{
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\shoes\Shoes_LeatherMoccasins_f.p3d";
			female="\DZ\characters\shoes\Shoes_LeatherMoccasins_f.p3d";
		};	
	};
};
class cfgWeapons
{
	class SawedoffMosin9130_Base;
	class B95_Base;
	class Izh43Shotgun_Base;
	class Izh18;
	class SawedoffMosin9130: SawedoffMosin9130_Base
	{
		scope=2;
		model="\dz\weapons\firearms\mosin9130\mosin_sawn.p3d";
		attachments[]=
		{
			"weaponOpticsMosin"
		};
		inventorySlot[]+=
		{
			"SawnOffWeapons"
		};
	};
	class SawedoffB95: B95_Base
	{
		scope=2;
		model="\dz\weapons\firearms\B95\b95_sawn.p3d";
		attachments[]+=
		{
			"weaponOpticsHunting"
		};
		inventorySlot[]=
		{
			"SawnOffWeapons"
		};
	};
	class SawedoffIzh43Shotgun: Izh43Shotgun_Base
	{
		scope=2;
		model="\dz\weapons\shotguns\Izh43\izh43_sawedoff.p3d";
		inventorySlot[]+=
		{
			"SawnOffWeapons"
		};
	};
	class SawedoffIzh18: Izh18
	{
		scope=2;
		model="\dz\weapons\firearms\Izh18\Izh18_sawedoff.p3d";
		inventorySlot[]+=
		{
			"SawnOffWeapons"
		};
	};
};