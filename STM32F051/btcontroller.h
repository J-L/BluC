/*
Header file includes declarations responsible for managing the bluetooth chip
//define hci commands




*/
struct hciCommandPacket{
	uint16 opcode;
	uint8 size; 
	uint8 data[0];
};
const SPIConfig hs_spicfg = {
  NULL,
  GPIOB,
  12,
  0,
  SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0
};

#define HCI_DISCONNECT 0x0406
#define HCI_READ_REMOTE_VERSION_INFORMATIOM 0x041D
#define HCI_SET_EVENT_MASK 0x0C01
#define HCI_RESET 0X0C03
#define HCI_READ_TRANSMIT_POWER_LEVEL 0x0C2D
#define HCI_READ_LOCAL_VERSION_INFORMATION 0x1001
#define HCL_READ_LOCAL_SUPPORTED_COMMANDS 0x1002
#define HCL_READ_LOCAL_SUPPORTED_FEATURES 0x1003
#define HCI_READ_BD_ADDR 0x1009
#define HCI_READ_RSSI 0x1405
#define HCI_LE_SET_EVENT_MASK 0x2001
#define HCI_LE_READ_BUFFER_SIZE 0x2002
#define HCI_LE_READ_LOCAL_SUPPORTED_FEATURE 0x2003
#define HCI_LE_SET_RANDOM_ADDRESS 0x2005
#define HCI_LE_SET_ADVERTIZING_PARAMETERS 0x2006
#define HCI_LE_READ_ADVERTISING_CHANNEL_TX_POWER 0x2007
#define HCI_LE_SET_ADVERTIZING_DATA 0x2008
#define HCI_LE_SET_SCAN_RESPONSE 0x2009
#define HCI_LE_SET_ADVERTIZE_ENABLE 0x200A
#define HCI_LE_SET_SCAN_ENABLE 0x200B
#define HCI_LE_CREATE_CONNECTION 0x200D
#define HCI_LE_CREATE_CONNECTIONC_CANCEL 0x200E
#define HCI_LE_CREATE_WHITE_LIST_SIZE 0x200F
#define HCI_LE_CLEAR_WHITE_LIST 0x2010
#define HCI_LE_ADD_DEVICE_TO_WHITE_LIST 0x2011
#define HCI_LE_REMOVE_DEVICE_FROM_WHITE_LIST 0x2012
#define HCI_LE_CONNECTION_UPDATE 0x2013
#define HCI_LE_SET_HOST_CHANNEL_CLASSIFICATION 0x2014
#define HCI_LE_READ_CHANNEL_MAP 0x2015
#define HCI_LE_READ_REMOTE_USED_FEATURES 0x2016
#define HCI_LE_ENCRYPT 0x2017
#define HCI_LE_RAND 0x2018
#define HCI_LE_START_ENCRYPTION 0x2019
#define HCI_LE_LONG_TERM_KEY_REQUEST_REPLY 0x201A
#define HCI_LE_LONG_TERM_KEY_REQUESTED_NEGATIVE_REPLY 0x201B
#define HCI_LE_READ_SUPPORTED_STATES 0x201C
#define HCI_LE_RECEIVER_TEST 0x201D
#define HCI_LE_TRANSMITTER_TEST 0x201E
#define HCI_LE_TEST_END 0x201F


#define DISCONNECT_COMPLETE 0x05
#define ENCRYPTION_CHANGE_EVENT 0x08
#define READ_REMOTEVERSION_INFORMATION_COMPLETE 0x0C
#define COMMAND_COMPLETE_EVENT 0x0E
#define COMMAND_STATUS_EVENT Ox0F
#define HARDWARE_ERROR_EVENT 0x10
#define NUMBER_COMPLETED_PACKETS 0x13
#define ENCRYPTION_KEYREFRESH_COMPLETE 0x30
#define LE_EVENT 0x3E
#define 
#define 
#define 





/*
btcheckmode:
	returns current status of bluetooth chip, at least as far as the mcu is
	aware.
	returns 0 if pin is set to configuration mode
	returns 1 if set to pass through mode
*/



/*
btsetmode:
in	sets pin on mcu responsible for config/passthrough mode
	returns 0 if successful
*/



/*
btcheckpower:
	returns status of bluetooths power
*/

/*
btsetpower:
	sets power pin on bluetooth chip according to passed variable
*/

/*
btsetup:
	uses struct to intialise bluetooth chip
*/

//bt higher level functions
int btSetupSpi(void);

int btCheckMode(void);
int btSetMode(int);
int btCheckPower(void);
int btSetPower(int);
int btCheckConnected(int);
int btSetup(int);
int btCheckRole(void);
int btSetRole(int);
int btSearchDevices(void);
int btFindDevName(int);
int btSetPassword(int);
int btCheckPassword(int);
int btCheckMyName(void);
int btMakeConnection(void);
int btBreakConnection(void);
int btSetBausRate(void);
int btCheckBaudRate(void);
int btSetInquiryMode(int);
int btReset(int);
int btSetClass(int);
int btCheckClass(void);
int btCheckStatus(void);




