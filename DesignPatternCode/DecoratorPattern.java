package DesignPatternCode;

// Component
interface Text{
    String print();
}

// ConcreteComponent
class NormalText implements Text{
    private String txt;
    public NormalText(String t){ this.txt = t;}
    
    @Override
    public String print(){
        return txt;
    }
}

// Decorator
abstract class TextDecorator implements Text{
    protected Text text;
    public TextDecorator(Text t){
        this.text = t;
    }
}

// ConcreteDecorator
class BoldText extends TextDecorator{
    public BoldText(Text text) { super(text);}
    
    public String print(){
        return "<b>" + text.print() + "</b>";
    }
}
class ItalicText extends TextDecorator{
    public ItalicText(Text text) {super(text);}
    
    public String print(){
        return "<i>" + text.print() + "</i>";
    }
}
class UnderlineText extends TextDecorator{
    public UnderlineText(Text text) {super(text);}
    
    public String print(){
        return "<u>" + text.print() + "</u>";
    }
}


class DecoratorPattern
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Text t1 = new NormalText("Hello i'm normal");
		System.out.println(t1.print());
		
		Text t2 = new BoldText(new NormalText("Hello i'm Bold"));
		System.out.println(t2.print());
		
		Text t3 = new ItalicText(new NormalText("Hello i'm Italic"));
		System.out.println(t3.print());
		
		Text t4 = new UnderlineText(new NormalText("Hello i'm Underline"));
		System.out.println(t4.print());
		
		Text t5 = new BoldText(new UnderlineText(new NormalText("Hello i'm Underline and Bold")));
		System.out.println(t5.print());
	}
}
