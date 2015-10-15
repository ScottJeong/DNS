/*
===============================================================================
 Name        : W5500-EVB_DNS.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif
#include "spi_handler.h"
#include "w5500_init.h"
//#include "board.h"
#include <cr_section_macros.h>
#include "socket.h"
#include "dhcp.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#define SOCK_TCPS0       0
#define SOCK_TCPS1       1
#define DATA_BUF_SIZE   2048
uint8_t gDATABUF[DATA_BUF_SIZE];

uint8_t DNS_Query()
{
	uint8_t ret;
	uint8_t dns_socket = SOCK_TCPS0;
	uint8_t DNS_SIP[4] = {8,8,8,8};
	//strcpy(DNS_SIP, dns);
	uint8_t DNS_SPORT = 53;

	//DNS Query Header Message
	uint16_t xid = 0x1234;
	uint16_t query_flag = 0x0100;
	uint16_t query_Qu_num = 1;	//Number of Question Records
	uint16_t query_An_num = 0;	//Number of Answer Records
	uint16_t query_Au_num = 0;	//Number of Authoritative Records
	uint16_t query_Ad_num = 0;	//Number of Additional Records

	//DNS Query Data Message
#define Q_DOMAIN_LEN  15
	uint8_t query_domain[Q_DOMAIN_LEN] = {3,'w','w','w',5,'n','a','v','e','r',3,'c','o','m',0};
	//uint8_t query_domain[Q_DOMAIN_LEN];
	//uint8_t query_domain_1[20] = "www.naver.com";

	uint16_t query_type = 1;
	uint16_t query_class = 1;

	//DNS Make Query Message
	uint8_t dns_Query_buf[100];
	uint8_t Qcnt = 0;

	//// Header
	dns_Query_buf[Qcnt++] = xid >> 8;
	dns_Query_buf[Qcnt++] = xid;
	dns_Query_buf[Qcnt++] = query_flag >> 8;
	dns_Query_buf[Qcnt++] = query_flag;
	dns_Query_buf[Qcnt++] = query_Qu_num >> 8;
	dns_Query_buf[Qcnt++] = query_Qu_num;
	dns_Query_buf[Qcnt++] = query_An_num >> 8;
	dns_Query_buf[Qcnt++] = query_An_num;
	dns_Query_buf[Qcnt++] = query_Au_num >> 8;
	dns_Query_buf[Qcnt++] = query_Au_num;
	dns_Query_buf[Qcnt++] = query_Ad_num >> 8;
	dns_Query_buf[Qcnt++] = query_Ad_num;

	//// Data
	uint8_t i;
	for(i = 0 ; i < Q_DOMAIN_LEN ; i++){
		dns_Query_buf[Qcnt++] = query_domain[i];
	}

	dns_Query_buf[Qcnt++] = query_type >> 8;
	dns_Query_buf[Qcnt++] = query_type;
	dns_Query_buf[Qcnt++] = query_class >> 8;
	dns_Query_buf[Qcnt++] = query_class;

	//DNS Socket open
	if( dns_socket == socket(dns_socket, Sn_MR_UDP, 0, 0) ){
		printf("%d Socket open\n\r", dns_socket);
	}

	//Sent DNS Query
	printf("> DNS Query to DNS Server : %3d.%3d.%3d.%3d\r\n", DNS_SIP[0], DNS_SIP[1], DNS_SIP[2], DNS_SIP[3]);
	ret = sendto(dns_socket, dns_Query_buf, Qcnt, DNS_SIP, DNS_SPORT);

	return ret;
}
int main(void) {

#if defined (__USE_LPCOPEN)
#if !defined(NO_BOARD_LIB)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif
    uint8_t ip[4] = {0,};
    uint8_t gw[4] = {0,};
    uint8_t sn[4] = {0,};
    uint8_t dns[4] = {0,};

    SPI_Init();
    W5500_Init();
    //Net_Conf();

//    if ( SOCK_TCPS0 == socket(SOCK_TCPS1,Sn_MR_UDP,DHCP_CLIENT_PORT,0) ){
//    	printf("%d Socket open\n\r", SOCK_TCPS1);
//    }

    DHCP_init(SOCK_TCPS0, gDATABUF);
    while (DHCP_run() != DHCP_IP_LEASED)	printf("."),delay_cnt(10000);
    printf("\r\n");
    Board_LED_Set(0, false);
    Board_LED_Set(1, true);
    getIPfromDHCP(ip);
    getGWfromDHCP(gw);
	getSNfromDHCP(sn);
	getDNSfromDHCP(dns);

	printf("< DHCP IP Leased!! >\r\n");
	//printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X\r\n", DHCP_CHADDR[0], DHCP_CHADDR[1], DHCP_CHADDR[2],  DHCP_CHADDR[3], DHCP_CHADDR[4], DHCP_CHADDR[0]);
	printf("IP	: %3d.%3d.%3d.%3d\r\n", ip[0], ip[1], ip[2], ip[3]);
	printf("GW	: %3d.%3d.%3d.%3d\r\n", gw[0], gw[1], gw[2], gw[3]);
	printf("SN	: %3d.%3d.%3d.%3d\r\n", sn[0], sn[1], sn[2], sn[3]);
	printf("DNS	: %3d.%3d.%3d.%3d\r\n", dns[0], dns[1], dns[2], dns[3]);
	DHCP_stop();

	DNS_Query();
    while(1) {

    }
    return 0 ;
}
