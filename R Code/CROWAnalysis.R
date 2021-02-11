# This script is an expansive practical use of R for plotting data
#  the main plots from this graph that have been utilized are:
#   showing the voltage of various nodes over time
#   showing the AVERAGED sodium channel gates in the phase plane (Plotting h vs m)

source("UsefulFunctions.R")
library(ggplot2)
library(gridExtra)
#C:\Users\Joey\Desktop\TestData\CROW\Data for heatmap for paper\PhasePlaneData\externalDC
external <- getDataAllDF("C://Users//Joey//Desktop//TestData//CROW//Data for heatmap for paper//PhasePlaneData//externalDC//")
internal <- getDataAllDF("C://Users//Joey//Desktop//TestData//CROW//Data for heatmap for paper//PhasePlaneData//internalDC//")
nope <- getDataAllDF("C://Users//Joey//Desktop//TestData//CROW//Data for heatmap for paper//PhasePlaneData//noDC//")
long <- getDataAllDF("C://Users//Joey//Desktop//TestData//CROW//Data for heatmap for paper//PhasePlaneData//longDC//")
dualDC <- getDataAllDF("C://Users//Joey//Desktop//TestData/CROW Modeling//relayPaperMultElectrode//")

df <- movingAverageDF(nope, 20)

p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  #geom_path( aes(x=M51,y=H51), size=1)+
  #geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M51,y=H51), colour="#666666", size=1, arrow=arrow())+
  #geom_point(aes(x=M51,y=H51), shape=1, size=1)+
  geom_path( aes(x=M50,y=H50), size=1)+
  geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M50,y=H50), colour="#666666", size=1, arrow=arrow())+
  #geom_point(aes(x=M50,y=H50), shape=2, size=1)+
  #geom_path( aes(x=M49,y=H49), size=1)+
  #geom_path( aes(x=M49,y=H49), arrow=arrow(angle=15, type="open"))+
  #geom_point(aes(x=M49,y=H49), shape=3, size=1)+
  #geom_path( aes(x=M48,y=H48), size=1)+
  #geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M48,y=H48), colour="#666666", size=1, arrow=arrow())+
  #geom_point(aes(x=M48,y=H48), shape=4, size=1)+
  #geom_path( aes(x=M41,y=H41), size=1)+
  #geom_path(data=df[df$Time>50 & df$Time<50.15,], aes(x=M50,y=H50), colour="#666666", size=1, arrow=arrow())+
  #geom_path( aes(x=M50,y=H50), size=1)+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
  #guides(color=FALSE,shape=guide_legend(order=1), fill=FALSE, size=FALSE)+
  #scale_shape_manual(name="Nodes", values=c(1,2,3,4), labels=c("Node 50", "Node 49", "Node 48", "Node 47"), guide="legend")+
  #labs(title="KHFAC Steady State",x="M Gate Probability", y="H Gate Probablility")

#p <- p + geom_path(data=df[df$Time>30 & df$Time<30.5,], aes(x=M48,y=V48), colour="grey", size=1, arrow=arrow())

show(p) 
ggsave("./CROW/avgArrowsEPS/NoDC_1 from Center.eps", p, height=10, width=10, units="cm")

#-----------------------------------
# CROW PHASE PLANE PLOTS External DC
#-----------------------------------
df <- movingAverageDF(long, 20)

#ExtDC_1 from center
p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path(data=df[df$Time>50 & df$Time<50.15,], aes(x=M50,y=H50), colour="#666666", size=1, arrow=arrow())+
  geom_path( aes(x=M50,y=H50), size=1)+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPS/ExtDC_1 from center.eps", p, height=10, width=10, units="cm")

#ExtDC_Center
p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path(data=df[df$Time>50 & df$Time<50.05,], aes(x=M51,y=H51), colour="#666666", size=1, arrow=arrow())+
  geom_path(aes(x=M51,y=H51, color=V51), size=1)+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPS/ExtDC_Center.eps", p, height=10, width=10, units="cm")

#ExtDC_3 from Center
p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path( aes(x=M48,y=H48), size=1)+
  geom_path(data=df[df$Time>50 & df$Time<50.7,], aes(x=M48,y=H48), colour="#666666", size=1, arrow=arrow())+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPS/ExtDC_3 from Center.eps", p, height=10, width=10, units="cm")

#-----------------------------------
# CROW PHASE PLANE PLOTS COLOR External DC
#-----------------------------------
df <- movingAverageDF(long, 20)

#ExtDC_1 from center
p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path(data=df[df$Time>50 & df$Time<50.15,], aes(x=M50,y=H50), colour="#666666", size=1, arrow=arrow())+
  geom_path( aes(x=M50,y=H50, color=V50), size=1)+
  scale_color_gradient2(midpoint = -20, low = "blue", mid = "red", high = "yellow")+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank(), legend.title = element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPSCOLOR/ExtDC_1 from centerCOLOR.eps", p, height=10, width=12, units="cm")
ggsave("./CROW/avgArrowsEPSCOLOR/ExtDC_1 from centerCOLOR.png", p, height=10, width=12, units="cm")

#ExtDC_Center
p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path(data=df[df$Time>50 & df$Time<50.05,], aes(x=M51,y=H51), colour="#666666", size=1, arrow=arrow())+
  geom_path(aes(x=M51,y=H51, color=V51), size=1)+
  scale_color_gradient2(midpoint = -20, low = "blue", mid = "red", high = "yellow")+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank(), legend.title = element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPSCOLOR/ExtDC_CenterCOLOR.eps", p, height=10, width=12, units="cm")
ggsave("./CROW/avgArrowsEPSCOLOR/ExtDC_CenterCOLOR.png", p, height=10, width=12, units="cm")

#ExtDC_3 from Center
p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path(data=df[df$Time>50 & df$Time<50.7,], aes(x=M48,y=H48), colour="#666666", size=1, arrow=arrow())+
  geom_path( aes(x=M48,y=H48, color=V48), size=1)+
  scale_color_gradient2(midpoint = -20, low = "blue", mid = "red", high = "yellow")+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank(), legend.title = element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPSCOLOR/ExtDC_3 from CenterCOLOR.eps", p, height=10, width=12, units="cm")
ggsave("./CROW/avgArrowsEPSCOLOR/ExtDC_3 from CenterCOLOR.png", p, height=10, width=12, units="cm")

p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path(data=df[df$Time>50 & df$Time<50.8,], aes(x=M41,y=H41), colour="#666666", size=1, arrow=arrow())+
  geom_path( aes(x=M41,y=H41, color=V41), size=1)+
  scale_color_gradient2(midpoint = -20, low = "blue", mid = "red", high = "yellow")+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank(), legend.title = element_blank())
show(p)
ggsave("./CROW/avgArrowsEPSCOLOR/ExtDC_10 from CenterCOLOR.eps", p, height=10, width=12, units="cm")
ggsave("./CROW/avgArrowsEPSCOLOR/ExtDC_10 from CenterCOLOR.png", p, height=10, width=12, units="cm")

#----------------------------------
# CROW PHASE PLANE TIME External DC
#----------------------------------
df <- movingAverageDF(long, 20)

#ExtDC_1 from center
p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path( aes(x=Time-50,y=M50), size=1, linetype=2)+
  geom_path( aes(x=Time-50,y=H50), size=1)+
  xlim(0,15)+
  ylim(0,1)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p)
ggsave("./CROW/avgOverTime/ExtDC_1 from center.eps", p, height=10, width=10, units="cm")
ggsave("./CROW/avgOverTime/ExtDC_1 from center.png", p, height=10, width=10, units="cm")

p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path( aes(x=Time-50,y=M51), size=1, linetype=2)+
  geom_path( aes(x=Time-50,y=H51), size=1)+
  xlim(0,15)+
  ylim(0,1)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p)
ggsave("./CROW/avgOverTime/ExtDC_Center.eps", p, height=10, width=10, units="cm")
ggsave("./CROW/avgOverTime/ExtDC_Center.png", p, height=10, width=10, units="cm")

p <- ggplot(data=df[df$Time>50 & df$Time<65,])+
  geom_path( aes(x=Time-50,y=M48), size=1, linetype=2)+
  geom_path( aes(x=Time-50,y=H48), size=1)+
  xlim(0,15)+
  ylim(0,1)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p)
ggsave("./CROW/avgOverTime/ExtDC_3 from Center.eps", p, height=10, width=10, units="cm")
ggsave("./CROW/avgOverTime/ExtDC_3 from Center.png", p, height=10, width=10, units="cm")


#-----------------------------
# CROW Phase plane plots no DC
#-----------------------------
df <- movingAverageDF(nope, 20)

# NoDC_3 from center
p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path( aes(x=M48,y=H48), size=1)+
  geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M48,y=H48), colour="#666666", size=1, arrow=arrow())+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPS/NoDC_3 from Center.eps", p, height=10, width=10, units="cm")

# NoDC_Center
p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path( aes(x=M51,y=H51), size=1)+
  geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M51,y=H51), colour="#666666", size=1, arrow=arrow())+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPS/NoDC_Center.eps", p, height=10, width=10, units="cm")

# NoDC_1 from Center
p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path( aes(x=M50,y=H50), size=1)+
  geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M50,y=H50), colour="#666666", size=1, arrow=arrow())+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPS/NoDC_1 from Center.eps", p, height=10, width=10, units="cm")

#-----------------------------
# CROW Phase plane plots no DC
#-----------------------------
df <- movingAverageDF(nope, 20)

# NoDC_3 from center
p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M48,y=H48), colour="#666666", size=1, arrow=arrow())+
  geom_path( aes(x=M48,y=H48, color=V48), size=1)+
  scale_color_gradient2(midpoint = -20, low = "blue", mid = "red", high = "yellow")+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank(), legend.title = element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPSCOLOR/NoDC_3 from CenterCOLOR.eps", p, height=10, width=12, units="cm")
ggsave("./CROW/avgArrowsEPSCOLOR/NoDC_3 from CenterCOLOR.png", p, height=10, width=12, units="cm")

# NoDC_Center
p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M51,y=H51), colour="#666666", size=1, arrow=arrow())+
  geom_path( aes(x=M51,y=H51, color=V51), size=1)+
  scale_color_gradient2(midpoint = -20, low = "blue", mid = "red", high = "yellow")+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank(), legend.title = element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPSCOLOR/NoDC_CenterCOLOR.eps", p, height=10, width=12, units="cm")
ggsave("./CROW/avgArrowsEPSCOLOR/NoDC_CenterCOLOR.png", p, height=10, width=12, units="cm")

# NoDC_1 from Center
p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path(data=df[df$Time>30 & df$Time<30.3,], aes(x=M50,y=H50), colour="#666666", size=1, arrow=arrow())+
  geom_path( aes(x=M50,y=H50, color=V50), size=1)+
  scale_color_gradient2(midpoint = -20, low = "blue", mid = "red", high = "yellow")+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank(), legend.title = element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPSCOLOR/NoDC_1 from CenterCOLOR.eps", p, height=10, width=12, units="cm")
ggsave("./CROW/avgArrowsEPSCOLOR/NoDC_1 from CenterCOLOR.png", p, height=10, width=12, units="cm")

p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path(data=df[df$Time>30 & df$Time<30.45,], aes(x=M41,y=H41), colour="#666666", size=1, arrow=arrow())+
  geom_path( aes(x=M41,y=H41, color=V41), size=1)+
  scale_color_gradient2(midpoint = -20, low = "blue", mid = "red", high = "yellow")+
  xlim(0,1)+
  ylim(0,.3)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank(), legend.title = element_blank())
show(p) 
ggsave("./CROW/avgArrowsEPSCOLOR/NoDC_10 from CenterCOLOR.eps", p, height=10, width=12, units="cm")
ggsave("./CROW/avgArrowsEPSCOLOR/NoDC_10 from CenterCOLOR.png", p, height=10, width=12, units="cm")
#------------------------------
# CROW Phase plane TIME no DC
#------------------------------
df <- movingAverageDF(nope, 20)

#noDC_1 from center
p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path( aes(x=Time-30,y=M50), size=1, linetype=2)+
  geom_path( aes(x=Time-30,y=H50), size=1)+
  xlim(0,15)+
  ylim(0,1)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p)
ggsave("./CROW/avgOverTime/NoDC_1 from center.eps", p, height=10, width=10, units="cm")
ggsave("./CROW/avgOverTime/NoDC_1 from center.png", p, height=10, width=10, units="cm")

p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path( aes(x=Time-30,y=M51), size=1, linetype=2)+
  geom_path( aes(x=Time-30,y=H51), size=1)+
  xlim(0,15)+
  ylim(0,1)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p)
ggsave("./CROW/avgOverTime/NoDC_Center.eps", p, height=10, width=10, units="cm")
ggsave("./CROW/avgOverTime/NoDC_Center.png", p, height=10, width=10, units="cm")

p <- ggplot(data=df[df$Time>30 & df$Time<45,])+
  geom_path( aes(x=Time-30,y=M48), size=1, linetype=2)+
  geom_path( aes(x=Time-30,y=H48), size=1)+
  xlim(0,15)+
  ylim(0,1)+
  theme(axis.title.x=element_blank(), axis.title.y=element_blank())
show(p)
ggsave("./CROW/avgOverTime/NoDC_3 from Center.eps", p, height=10, width=10, units="cm")
ggsave("./CROW/avgOverTime/NoDC_3 from Center.png", p, height=10, width=10, units="cm")
#-----------------------
# Multiple Voltage Plots
#-----------------------
x<- c(0,1,2,3,4,5)
y<- c(0,3,4,5,6,7)
p1 <- plot(x,y)
p2 <- plot(y,x)
p3 <- grid.arrange(p1, p2, ncol=2)

# Sample code to play with
df <- movingAverageDF(nope, 20)
vp <- ggplot(data=df[df$Time>0 & df$Time<65,])+
  geom_path(aes(x=Time-20,y=V51), size=1, color="#000000", linetype="solid")+
  geom_path(aes(x=Time-20,y=V50), size=1, color="#333333", linetype="longdash")+
  geom_path(aes(x=Time-20,y=V48), size=1, color="#666666", linetype="solid")+
  geom_path(aes(x=Time-20,y=V41), size=1, color="#999999", linetype="longdash")+
  geom_path(aes(x=Time-20,y=V1), size=1, color="#BBBBBB", linetype="dashed")+
  xlim(0,25)+
  ylim(-120,100)+
  xlab("Time (ms)")+
  #xlab("")+
  #ylab("")+
  ylab("Voltage Moving Average (mV)")+
  ggtitle("No DC Stimulation Before KHFAC") +
  theme(plot.title = element_text(hjust = 0.5))
show(vp)
ggsave("./CROW/vProfileEPS/NoDC.eps", vp, height=10, width=25, units="cm")

# LongDCZoomed
df <- movingAverageDF(long, 20)
vp <- ggplot(data=df[df$Time>0 & df$Time<65,])+
  geom_path(aes(x=Time-0,y=V51), size=1, color="#000000", linetype="solid")+
  geom_path(aes(x=Time-0,y=V50), size=1, color="#333333", linetype="longdash")+
  geom_path(aes(x=Time-0,y=V48), size=1, color="#666666", linetype="solid")+
  geom_path(aes(x=Time-0,y=V41), size=1, color="#999999", linetype="longdash")+
  geom_path(aes(x=Time-0,y=V1), size=1, color="#BBBBBB", linetype="dashed")+
  xlim(40,65)+
  ylim(-120,100)+
  xlab("Time (ms)")+
  ylab("Voltage Moving Average (mV)")+
  ggtitle("40ms DC Stimulation Before KHFAC") +
  theme(plot.title = element_text(hjust = 0.5))
show(vp)

# LongDCFull
df <- movingAverageDF(long, 20)
vp <- ggplot(data=df[df$Time>0 & df$Time<65,])+
  geom_path(aes(x=Time-0,y=V51), size=1, color="#000000", linetype="solid")+
  geom_path(aes(x=Time-0,y=V50), size=1, color="#333333", linetype="longdash")+
  geom_path(aes(x=Time-0,y=V48), size=1, color="#666666", linetype="solid")+
  geom_path(aes(x=Time-0,y=V41), size=1, color="#999999", linetype="longdash")+
  geom_path(aes(x=Time-0,y=V1), size=1, color="#BBBBBB", linetype="dashed")+
  xlim(0,65)+
  ylim(-120,100)+
  xlab("")+
  ylab("")+
  theme(plot.title = element_text(hjust = 0.5))
show(vp)
ggsave("./CROW/vProfileEPS/LongDCFull.eps", vp, height=10, width=25, units="cm")

# NoDC
df <- movingAverageDF(nope, 20)
vp <- ggplot(data=df[df$Time>0 & df$Time<65,])+
  geom_path(aes(x=Time-20,y=V51), size=1, color="#000000", linetype="solid")+
  geom_path(aes(x=Time-20,y=V50), size=1, color="#333333", linetype="longdash")+
  geom_path(aes(x=Time-20,y=V48), size=1, color="#666666", linetype="solid")+
  geom_path(aes(x=Time-20,y=V41), size=1, color="#999999", linetype="longdash")+
  geom_path(aes(x=Time-20,y=V1), size=1, color="#BBBBBB", linetype="dashed")+
  xlim(0,25)+
  ylim(-120,100)+
  xlab("Time (ms)")+
  ylab("Voltage Moving Average (mV)")+
  ggtitle("No DC Stimulation Before KHFAC") +
  theme(plot.title = element_text(hjust = 0.5))
show(vp)
ggsave("./CROW/vProfileEPS/NoDC.eps", vp, height=10, width=25, units="cm")

#----
#notes

#nodc0 - 29-30.1
#intdc1 - 31-31.1
#extdc1 - 31-31.1
#int/no/extdc2 - 39-39.1
#int/no/extdc3 - 80-80.1

#-----------
# CROW GIF
#-----------
all2DF <- long
for (num in seq(0,5,by=.1)){
  cat(num)
  cat("\n")
  if(num>0.75){
    plot <- ggplot()+
      geom_path(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M47,y=H47), color="green", size=1)+
      geom_path(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M48,y=H48), color="blue", size=1)+
      geom_path(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M49,y=H49), color="purple", size=1)+
      geom_path(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M50,y=H50), color="red", size=1)+
      geom_path(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M51,y=H51), color="orange", size=1)+
      #scale_colour_gradient2(low = "black", high = "red", mid="orange", midpoint = -50)+
      xlim(0,1)+
      ylim(0,1)+
      xlab("M Gate Probability")+
      ylab("H Gate Probability")+
      ggtitle(paste("External DC", num-1, sep=" ", collapse = NULL))
    
    plot2 <- ggplot()+
      geom_path(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M47,y=H47), color="green", size=1)+
      geom_path(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M48,y=H48), color="blue", size=1)+
      geom_path(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M49,y=H49), color="purple", size=1)+
      geom_path(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M50,y=H50), color="red", size=1)+
      geom_path(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M51,y=H51), color="orange", size=1)+
      #scale_colour_gradient2(low = "black", high = "red", mid="orange", midpoint = -50)+
      xlim(0,1)+
      ylim(0,1)+
      xlab("M Gate Probability")+
      ylab("H Gate Probability")+
      ggtitle(paste("No DC", num-1, sep=" ", collapse = NULL))
  } else{
    plot <- ggplot()+
      geom_point(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M47,y=H47), color="green", size=2)+
      geom_point(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M48,y=H48), color="blue", size=2)+
      geom_point(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M49,y=H49), color="purple", size=2)+
      geom_point(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M50,y=H50), color="red", size=2)+
      geom_point(data = long[long$Time>num+49 & long$Time<num+49.3,], aes(x=M51,y=H51), color="orange", size=2)+
      #scale_colour_gradient2(low = "black", high = "red", mid="orange", midpoint = -50)+
      xlim(0,1)+
      ylim(0,1)+
      xlab("M Gate Probability")+
      ylab("H Gate Probability")+
      ggtitle(paste("External DC", num-1, sep=" ", collapse = NULL))
    
    plot2 <- ggplot()+
      geom_point(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M47,y=H47), color="green", size=2)+
      geom_point(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M48,y=H48), color="blue", size=2)+
      geom_point(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M49,y=H49), color="purple", size=2)+
      geom_point(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M50,y=H50), color="red", size=2)+
      geom_point(data = nope[nope$Time>num+29 & nope$Time<num+29.3,], aes(x=M51,y=H51), color="orange", size=2)+
      #scale_colour_gradient2(low = "black", high = "red", mid="orange", midpoint = -50)+
      xlim(0,1)+
      ylim(0,1)+
      xlab("M Gate Probability")+
      ylab("H Gate Probability")+
      ggtitle(paste("No DC", num-1, sep=" ", collapse = NULL))
  }
  p3 <- grid.arrange(plot2, plot, ncol=2)
  ggsave(filename = paste0("./CROWgif3/", sprintf("%05d",(num+50)*100),".png"), p3, width = 12, height = 6, dpi=150)
}
list.files(path = "./CROWgif3/", pattern = "*.png", full.names = T) %>%
  map(image_read) %>%
  image_join() %>%
  image_animate(fps=2.5) %>%
  image_write("CROW Comparison slow first 5.gif")

#-------------------
# relay paper graphs
#-------------------
dfMain <- movingAverageDF(dualDC, 20)
for(num in seq(0,60,by=0.5)){
  df <- dfMain[dfMain$Time<num,]
  p1 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M46, y=H46), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M46, y=H46), color="#FF0000")+
    xlim(0,1)+
    ylim(0,1)+
    xlab("M Gate")+
    ylab("H Gate")+
    ggtitle("Node 46")+
    theme(plot.title = element_text(hjust = 0.5))
  show(p1)
  s1 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M46, y=H46), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M46, y=H46), color="#FF0000")+
    xlim(0,1)+
    xlab("M Gate")+
    ylab("H Gate")+
    ylim(0,0.3)
  
  p2 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M50, y=H50), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M50, y=H50), color="#FF0000")+
    xlim(0,1)+
    ylim(0,1)+
    xlab("M Gate")+
    ylab("")+
    ggtitle("Node 50")+
    theme(plot.title = element_text(hjust = 0.5))
  s2 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M50, y=H50), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M50, y=H50), color="#FF0000")+
    xlim(0,1)+
    xlab("M Gate")+
    ylab("")+
    ylim(0,0.3)
  
  p3 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M51, y=H51), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M51, y=H51), color="#FF0000")+
    xlim(0,1)+
    ylim(0,1)+
    xlab("M Gate")+
    ylab("")+
    ggtitle("Node 51")+
    theme(plot.title = element_text(hjust = 0.5))
  s3 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M51, y=H51), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M51, y=H51), color="#FF0000")+
    xlim(0,1)+
    xlab("M Gate")+
    ylab("")+
    ylim(0,0.3)
  
  p4 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M52, y=H52), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M52, y=H52), color="#FF0000")+
    xlim(0,1)+
    ylim(0,1)+
    xlab("M Gate")+
    ylab("")+
    ggtitle("Node 52")+
    theme(plot.title = element_text(hjust = 0.5))
  s4 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M52, y=H52), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M52, y=H52), color="#FF0000")+
    xlim(0,1)+
    xlab("M Gate")+
    ylab("")+
    ylim(0,0.3)
  
  p5 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M56, y=H56), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M56, y=H56), color="#FF0000")+
    xlim(0,1)+
    ylim(0,1)+
    xlab("M Gate")+
    ylab("")+
    ggtitle("Node 56")+
    theme(plot.title = element_text(hjust = 0.5))
  s5 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=M56, y=H56), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=M56, y=H56), color="#FF0000")+
    xlim(0,1)+
    xlab("M Gate")+
    ylab("")+
    ylim(0,0.3)
  
  # voltage plots
  p6 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=Time, y=V46), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=Time, y=V46), color="#FF0000")+
    xlab("Time (ms)")+
    ylab("Voltage (mV)")+
    ylim(-100,50)+
    xlim(0,60)
  p7 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=Time, y=V50), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=Time, y=V50), color="#FF0000")+
    xlab("Time (ms)")+
    ylab("")+
    ylim(-100,50)+
    xlim(0,60)
  p8 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=Time, y=V51), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=Time, y=V51), color="#FF0000")+
    xlab("Time (ms)")+
    ylab("")+
    ylim(-100,50)+
    xlim(0,60)
  p9 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=Time, y=V52), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=Time, y=V52), color="#FF0000")+
    xlab("Time (ms)")+
    ylab("")+
    ylim(-100,50)+
    xlim(0,60)
  p10 <- ggplot()+
    geom_path(data=df[df$Time<60,], aes(x=Time, y=V56), color="#0000FF")+
    geom_path(data=df[df$Time<30,], aes(x=Time, y=V56), color="#FF0000")+
    xlab("Time (ms)")+
    ylab("")+
    ylim(-100,50)+
    xlim(0,60)
  
  
  # comine sodium channel and voltage plots
  plotGrid <- grid.arrange(p1,p2,p3,p4,p5,s1,s2,s3,s4,s5,p6,p7,p8,p9,p10, ncol=5)
  ggsave(filename = paste0("./CROWBipolar/", sprintf("%05d",(num+50)*100),".png"), plotGrid, width = 12, height = 6, dpi=150)
}


#----------------------
# calc m and h distance
#----------------------
show(p1)
df2 <- slopeDF(df, c("M49","H49"))
dist <- sqrt((df2$M49*df2$M49)+(df2$H49*df2$H49))
cbind(df2,dist)
summary(df2$Time)
ggplot(data=df2[df2$Time>5 & df2$Time<40,])+geom_path(aes(x=M49,y=H49, colour=Time))+
  xlim(-0.001, 0.001)+
  ylim(-0.001, 0.001)

