typedef uint8_t uint8_t;

class num2x2 {
	struct digitMatrixes {
		uint8_t _matrix[8];
	};

	digitMatrixes matrix[8] {
		{
			{
				0b11111,
				0b11111,
				0b11000,
				0b11000,
				0b11000,
				0b11000,
				0b11000,
				0b11000,
			}
		}, 
		{
			{
				0b11111,
				0b11111,
				0b00011,
				0b00011,
				0b00011,
				0b00011,
				0b00011,
				0b00011,
			}
		}, 
		{
			{
				0b11000,
				0b11000,
				0b11000,
				0b11000,
				0b11000,
				0b11000,
				0b11111,
				0b11111,
			}
		}, 
		{
			{
				0b00011,
				0b00011,
				0b00011,
				0b00011,
				0b00011,
				0b00011,
				0b11111,
				0b11111,
			}// ---
		}, 
		{
			{
				0b11111, // also "-" character
				0b11111,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
			}
		}, 
		{
			{
				0b11111,
				0b11111,
				0b11000,
				0b11000,
				0b11000,
				0b11000,
				0b11111,
				0b11111,
			}
		}, 
		{
			{
				0b11111,
				0b11111,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b11111,
				0b11111,
			}
		}, 
		{
			{
				0b11111,
				0b11111,
				0b00011,
				0b00011,
				0b00011,
				0b00011,
				0b11111,
				0b11111,
			}
		},
	};
		
		uint8_t num2x2_def[10][4] = { // 9 here is used for empty segment
		{0,1,2,3}, {9,1,9,3}, {4,1,5,6}, {4,1,6,7}, {2,3,4,1} , // 0,1,2,3,4
		{0,4,6,7}, {0,4,5,7}, {4,1,9,1}, {0,1,5,7}, {0,1,6,7}, //5,6,7,8,9
		};
		
	protected:
		LiquidCrystal  *_lcd;
		
	public:
		num2x2(LiquidCrystal *lcd) : _lcd(lcd) { };
		
		void init(){
			for(int i=0; i<8; i++){
				_lcd->createChar(i, matrix[i]._matrix);
			}
		}
		
		void printMinus(uint8_t _posX, uint8_t _posY){
			_lcd->setCursor(_posX, _posY+1);
			_lcd->write((uint8_t)4);
		}
		
		void printDigit(uint8_t _posX, uint8_t _posY, uint8_t _dig2x2){
			
			if(_dig2x2>9)
				return;
			
			short printCounter = 0; 
			
			for(int i=0; i<2; i++){
				for(int j=0; j<2; j++){					
					_lcd->setCursor(_posX + j, _posY + i);
					if(num2x2_def[_dig2x2][printCounter] == 9)
						_lcd->print(" ");
					else
						_lcd->write((uint8_t)num2x2_def[_dig2x2][printCounter]);
					printCounter++;
				}
			}
			
		}
		
		void printNum(uint8_t _posX, uint8_t _posY, long long int _num2x2){
			
			if(_num2x2<0){
				printMinus(_posX, _posY);
				_posX += 2;
				_num2x2 = abs(_num2x2);
			}
			
			uint8_t count = 1;
			long long int _n = _num2x2;
			while(_n = _n/10)
				count++;
			short num2x2_array[count];
			for(int i=count-1; i>=0; i--){
				num2x2_array[i] = _num2x2%10;
				_num2x2 = _num2x2/10;
			}
			
			//uint8_t _shiftX = _posX;
			
			for(int i=0; i<count; i++){
				printDigit(_posX, _posY, num2x2_array[i]);
				_posX += 2;
			}
			
		}
	
};
