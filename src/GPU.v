module GPU(
    input wire clk,
    input wire [5:0] x_addr,
    input wire [4:0] y_addr,
    input wire [7:0] sprite,
    input wire we_stb,

    output wire [2:0] disp_rgb,
    output wire hsync,
    output wire vsync
);

reg vga_clk;
reg [9:0] hcount;
reg [9:0] vcount;

reg [63:0] framebuffer [31:0];

wire  hcount_ov;
wire  vcount_ov;
wire  data_act;

reg bw_bit;

// copied from board reference design
parameter hsync_end   = 10'd95,
   hdat_begin  = 10'd143,
   hdat_end  = 10'd783,
   hpixel_end  = 10'd799,
   vsync_end  = 10'd1,
   vdat_begin  = 10'd34,
   vdat_end  = 10'd514,
   vline_end  = 10'd524;


// we need to divide our 50MHz clock to 25MHz to meet VGA timing
always @(posedge clk) begin
    vga_clk <= ~vga_clk;
end

// counts horizontal scanlines
always @(posedge vga_clk) begin
    if (hcount_ov)
        hcount <= 10'd0;
    else
        hcount <= hcount + 10'd1;
end
assign hcount_ov = (hcount == hpixel_end);

// counts vertical scanlines
always @(posedge vga_clk) begin
    if (hcount_ov) begin
        if (vcount_ov)
            vcount <= 10'd0;
        else
            vcount <= vcount + 10'd1;
    end
end
assign  vcount_ov = (vcount == vline_end);

// is out data valid?
assign data_act =    ((hcount >= hdat_begin) && (hcount < hdat_end))
     && ((vcount >= vdat_begin) && (vcount < vdat_end));
assign hsync = (hcount > hsync_end);
assign vsync = (vcount > vsync_end);
// so we don't display anything during guard periods
assign disp_rgb = {(10'd3){bw_bit}};

// 640/16 = 40, vamos repetir as 8 primeiras linhas
wire [9:0] line; 
assign line = ((vcount - vdat_begin));
// 800/8 = 100, vamos repetir as primeiras 36 linhas...
wire [9:0] column; 
assign column= ((hcount - hdat_begin));
always @(posedge vga_clk) begin
    if (data_act)
    bw_bit <= framebuffer[line[4:0]][column[5:0]];
    else
        bw_bit <= 1'b0;
end

// allows writing to the framebuffer
always @(posedge clk) begin
    if(we_stb) begin
        framebuffer[y_addr][x_addr] <= sprite[0];
        framebuffer[y_addr][x_addr+1] <= sprite[1];
        framebuffer[y_addr][x_addr+2] <= sprite[2];
        framebuffer[y_addr][x_addr+3] <= sprite[3];
        framebuffer[y_addr][x_addr+4] <= sprite[4];
        framebuffer[y_addr][x_addr+5] <= sprite[5];
        framebuffer[y_addr][x_addr+6] <= sprite[6];
        framebuffer[y_addr][x_addr+7] <= sprite[7];
    end
end

endmodule
