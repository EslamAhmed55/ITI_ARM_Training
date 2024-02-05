
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPI1_BASE								0x40013000UL
#define SPI2_BASE								0x40003800UL
#define SPI3_BASE								0x40003C00UL



typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SSPR;




}SPI_Typedef;

#define SPI1									((SPI_Typedef *)SPI1_BASE)
#define SPI2									((SPI_Typedef *)SPI2_BASE)
#define SPI3									((SPI_Typedef *)SPI3_BASE)

#endif 
