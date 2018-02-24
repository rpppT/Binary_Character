
import java.util.*;

 
public class Main{
	private String input;
	private Scanner scan;
	private ArrayList<String> list;
	
	private char [] array;
	private String [] decode_array;
	private String full_Binary;
	
	public Main(Scanner scan, ArrayList<String> list) {
		super();
		this.scan = scan;
		this.list = list;
	}
	public Main(){
		this(new Scanner(System.in), new ArrayList<String>());
		//exit Constructet this()
		
		System.out.println("Input your data(String)");
		this.input = this.scan.nextLine();
		this.array = new char[this.input.length()];
		this.decode_array = new String[this.array.length];
		this.full_Binary = "";
	}
	
	public void Convert_String() {
		int i, len;
		String temp;
		
		for(i=0; i<input.length(); i++) {
			array[i] = input.charAt(i);
		}

		
		for(i=0; i<array.length; i++) {
			temp=Integer.toBinaryString(array[i]);
		
			if(temp.length()<16) {
				len = 16-temp.length();
				for(int j=1; j<=len; j++) {
					temp = "0"+ temp;
				}
			}
			list.add(temp);
			
			this.full_Binary += temp;
		}
		
		System.out.println("Full Binary : "+this.full_Binary);
		Decode_String();
	}
	public void Decode_String() {
		int i, index;
		int save_binary=0;
		int max = 0;
		index  = 0;
	
		
		array = new char[input.length()];
		
		for(i=0; i<this.decode_array.length; i++) {
			decode_array[i] = full_Binary.substring(index, index+16);
			index += 16;
		}
		System.out.println(Arrays.toString(decode_array));
		for(i=0; i<decode_array.length; i++) {
			System.out.println("============index["+i+"]==============");
			for(int j = 0; j<decode_array[i].length(); j++) {
				if(decode_array[i].charAt(j)=='1') {
					max = 15;
					max -= j;
					System.out.print(save_binary+" + ");
					save_binary += 1 << max;
					System.out.println((1<<max)+" = "+save_binary);
				}
			}
			array[i] = (char)save_binary;
			save_binary = 0;
		}
		System.out.println(array);
	}
	public static void main(String[] args) {
		new Main().Convert_String();
	}
}


