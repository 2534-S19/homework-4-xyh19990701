#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework4.h"
unsigned int uart_r_tem=0;
char uart_s[30],uart_rn=0,uart_sn=0,trans_uart=0;
unsigned int  uart_r[1010]={0,0,0,0,},rchar, i =0 ;
const  eUSCI_UART_ConfigV1  uartConfig =
{
   EUSCI_A_UART_CLOCKSOURCE_SMCLK,
   19,
   8,
   0x55,
   EUSCI_A_UART_NO_PARITY,                       // No Parity
   EUSCI_A_UART_LSB_FIRST,                       // LSB First
   EUSCI_A_UART_ONE_STOP_BIT,                    // One stop bit
   EUSCI_A_UART_MODE,                            // UART mode
   EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION // Oversampling
};

void function(void)
{
    EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'\n');
    EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'\n');
    EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'\r');

                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'2');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'5');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'3');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'4');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,' ');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'i');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'s');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,' ');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'t');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'h');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'e');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,' ');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'b');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'e');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'s');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'t');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,' ');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'c');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'o');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'u');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'r');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'s');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'e');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,' ');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'i');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'n');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,' ');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'t');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'h');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'e');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,' ');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'c');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'u');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'r');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'r');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'i');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'c');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'u');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'l');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'u');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'m');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'!');

                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'\n');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'\n');
                  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'\r');
}
void main(void)
{
       uart_s[0] = '2534 is the best course in the curriculum!';
       initBoard();
       //  Declare a UART config struct as defined in uart.h.
       // To begin, configure the UART for 9600 baud, 8-bit payload (LSB first), no parity, 1 stop bit.
       // Make sure Tx AND Rx pins of EUSCI_A0 work for UART and not as regular GPIO pins.
       GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,GPIO_PIN2,GPIO_PRIMARY_MODULE_FUNCTION);
       GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1,GPIO_PIN3,GPIO_PRIMARY_MODULE_FUNCTION);

       UART_initModule(EUSCI_A0_BASE, &uartConfig);
       UART_enableModule(EUSCI_A0_BASE);
        UART_enableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
       Interrupt_enableMaster();

    while(1)
    {
        for ( i = 0; i<=1000 ; i++)
           {
   if ((uart_r[i]==2) & (uart_r[i+1]==5)& (uart_r[i+2]==3)&(uart_r[i+3]==4) ) {function();uart_r[i]=0;}
           }
    if (UART_getInterruptStatus (EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
                      == EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)  {
    if(('0'<=UART_receiveData(EUSCI_A0_BASE))&(UART_receiveData(EUSCI_A0_BASE)<'9'))
       {
            EUSCI_A_UART_transmitData(EUSCI_A0_BASE,UART_receiveData(EUSCI_A0_BASE));
                uart_r[uart_rn]=UART_receiveData(EUSCI_A0_BASE)&0x0f;
                if(uart_rn>=30)uart_rn=0;else uart_rn++;
            }
    }

        }

    }


void EUSCIA0_IRQHandler(void)
{
   ;
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

//  FSM for detecting character sequence.
bool charFSM(char rChar)
{
    bool finished = false;
    return finished;
}
